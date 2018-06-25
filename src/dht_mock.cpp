#include "dht_mock.hpp"

#include "wrap-hwlib.hpp"
DHTMock::DHTMock(hwlib::pin_in_out &pinData) : DHT(pinData, 200000) {
}

void DHTMock::sampleEnvironment() {
    temperature = desire_temperature;
}

void DHTMock::setTemperature(int temp) {
    desire_temperature = temp;
    temperature = temp;
}
