#include "DHT22.hpp"

DHT22::DHT22(int pinData) : pinDATA(pinData) {
    temperature = 10;
}

int DHT22::getTemperature() {
    return temperature;
}

int DHT22::getPinDATA() {
    return pinDATA;
}
