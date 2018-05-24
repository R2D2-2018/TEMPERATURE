#include "DHT22.hpp"
#include "wrap-hwlib.hpp"

int main() {
    WDT->WDT_MR = WDT_MR_WDDIS;

    DHT22 dht22(7);

    hwlib::wait_ms(1000);
    hwlib::cout << "Current Temperature: " << dht22.getTemperature() << "\n" << hwlib::endl;

    return 0;
}