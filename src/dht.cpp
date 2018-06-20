#include "dht.hpp"
#include "wrap-hwlib.hpp"
DHT::DHT(hwlib::pin_in_out &pinData, int sensorUpdateInterval)
    : lastUpdate(0), sensorUpdateInterval(sensorUpdateInterval), pin(pinData) {
}

bool DHT::checksum() {
    return ((data[0] + data[1] + data[2] + data[3]) == data[4]);
}

void DHT::dhtWrite(char cmd) {
    pin.direction_set_output();
    if (cmd == 'r') {
        pin.set(0);
        hwlib::wait_ms(20);
        pin.set(1);
        hwlib::wait_us(30);
    }

    pin.direction_set_input();
}

int DHT::dhtWait() {
    int waitTime = 0;
    int timeOut = 8000;
    waitTime = 0;
    while (pin.get() != 1) {
        if (waitTime >= timeOut) {
            return 0;
        }
        waitTime++;
    }
    while (pin.get() != 0) {
        if (waitTime >= timeOut) {
            return 0;
        }
        waitTime++;
    }
    return 1;
}

int DHT::dhtGetBits() {
    int waitTime = 0;
    int timeOut = 8000;
    int bitTime = 0;
    int bitTimeCompare = 0;
    for (auto &byte : data) {
        for (int b = 7; b >= 0; b--) {
            waitTime = 0;
            while (pin.get() != 1) {
                if (waitTime >= timeOut) {
                    return 0;
                }
                waitTime++;
            }

            waitTime = 0;
            bitTime = hwlib::now_us();
            while (pin.get() != 0) {
                if (waitTime >= timeOut) {
                    return 0;
                }
                waitTime++;
            }

            bitTimeCompare = hwlib::now_us();
            if ((bitTimeCompare - bitTime) > 40) {
                byte |= (1 << b);
            }
        }
    }
    return checksum();
}

int DHT::dhtRead() {
    dhtWait();
    return dhtGetBits();
}

int DHT::getTemperature() {
    if (hwlib::now_us() - lastUpdate > 200000) {
        lastUpdate = hwlib::now_us();
        sampleEnvironment();
    }
    return temperature;
}