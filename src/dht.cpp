#include "DHT.hpp"

DHT::DHT(int pinData) : pinDATA(pinData) {
    temperature = 10;
}

int DHT::getTemperature() {
    return temperature;
}

int DHT::getPinDATA() {
    return pinDATA;
}
