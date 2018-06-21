#include "dht_11.hpp"
#include "dht_22.hpp"
#include "wrap-hwlib.hpp"
// Need because temperature contains a pure virutal function1 see:
// https://stackoverflow.com/questions/920500/what-is-the-purpose-of-cxa-pure-virtual for more information.
extern "C" void __cxa_pure_virtual();
extern "C" void __cxa_pure_virtual() {
    while (true) {
    }
}

int main() {
    WDT->WDT_MR = WDT_MR_WDDIS;

    auto pin_dht11 = hwlib::target::pin_in_out(hwlib::target::pins::a3);
    DHT11 dht11 = DHT11(pin_dht11);

    auto pin_dht22 = hwlib::target::pin_in_out(hwlib::target::pins::a4);
    DHT22 dht22 = DHT22(pin_dht22);
    hwlib::wait_ms(1200);

    while (true) {
        hwlib::cout << "DHT11: " << dht11.getTemperature() << '\r' << '\n';
        hwlib::cout << "DHT22: " << dht22.getTemperature() << '\r' << '\n';
        hwlib::wait_ms(1500);
    }

    return 0;
}