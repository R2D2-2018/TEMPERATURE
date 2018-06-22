#include "dht_11.hpp"
#include "wrap-hwlib.hpp"
DHT11::DHT11(hwlib::pin_in_out &pinData) : DHT(pinData) {
}

void DHT11::sampleEnvironment() {
    for (auto &byte : data) {
        byte = 0;
    }
    dhtWrite('r');
    dhtRead();
    if (checksum() == 1) {
        temperature = int(data[2]);
    }
}