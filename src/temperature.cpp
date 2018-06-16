#include "temperature.hpp"

Temperature::Temperature() {
    ;
}

void Temperature::setTreshold(int in_treshold) {
    treshold = in_treshold;
}

int Temperature::getTreshold() {
    return treshold;
}

bool Temperature::checkTreshold() {
    return false;
}