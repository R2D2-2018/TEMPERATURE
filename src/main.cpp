#include "dht.hpp"
#include "wrap-hwlib.hpp"
#include <array>
#include <bitset>

int pinRead(hwlib::target::pin_in_out pin);
int printBits();

int main() {
    WDT->WDT_MR = WDT_MR_WDDIS;

    hwlib::wait_ms(1200);
    auto pin = hwlib::target::pin_in_out(hwlib::target::pins::a3);
    while (true) {
        pinRead(pin);
        hwlib::wait_ms(2000);
    }

    return 0;
}

int printBits(uint8_t byte) {
    std::array<uint8_t, 5> data = {5, 5, 101, 2, 15};
    for (int i = 8; i >= 0; i--) {
        hwlib::cout << ((byte >> i) & 1);
    }
    hwlib::cout << '\n';
    return 0;
}

int pinRead(hwlib::target::pin_in_out pin) {
    hwlib::cout << "pinRead()\n";
    int timeOut = 8000;
    int waitTime = 0;
    int bitTime = 0;
    int bitTimeCompare = 0;
    std::array<uint8_t, 5> data = {0, 0, 0, 0, 0};

    // start transmission command
    pin.direction_set_output();
    pin.set(0);
    hwlib::wait_ms(20);
    pin.set(1);
    hwlib::wait_us(30);
    pin.direction_set_input();

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

    // obtaining the bits
    for (auto &byte : data) {
        for (int b = 0; b < 8; b++) {
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
            if ((bitTimeCompare - bitTime) > 30) {
                // hwlib::cout << '1';
                byte |= (1 << b);
            }
        }
    }

    for (const auto &byte : data) {
        for (int i = 8; i >= 0; i--) {
            hwlib::cout << ((byte >> i) & 1);
        }
        hwlib::cout << '\n';
    }

    hwlib::cout << '\n';
    return 0;
}