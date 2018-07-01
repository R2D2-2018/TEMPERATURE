#include "dht_mock.hpp"

#include "wrap-hwlib.hpp"
DHTMock::DHTMock(hwlib::pin_in_out &pinData) : DHT(pinData, 200000) {
}

void DHTMock::sampleEnvironment() {
    temperature = desireTemperature;
}

void DHTMock::setTemperature(int temp) {
    desireTemperature = temp;
    temperature = temp;
}
