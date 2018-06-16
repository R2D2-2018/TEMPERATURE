#include "dht_22.hpp"

#include "wrap-hwlib.hpp"
DHT22::DHT22(hwlib::pin_in_out &pinData) : DHT(pinData) {
    sampleEnvironment();
}

void DHT22::sampleEnvironment() {
    for (auto &byte : data) {
        byte = 0;
    }
    dhtWrite('r');
    dhtRead();
    if (checksum()) {
        temperature = int(data[3]) / 10;
    }
}