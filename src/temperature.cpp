#include "temperature.hpp"
#include "wrap-hwlib.hpp"
Temperature::Temperature() : treshold(0), temperature(0) {
    ;
}

void Temperature::setTreshold(int in_treshold) {
    treshold = in_treshold;
}

int Temperature::getTreshold() {
    return treshold;
}

bool Temperature::checkTreshold() {
    return getTemperature() > treshold;
}