#include "dht.hpp"
#include "wrap-hwlib.hpp"
#include <array>
#include <bitset>

int main() {
    WDT->WDT_MR = WDT_MR_WDDIS;

    auto pin = hwlib::target::pin_in_out(hwlib::target::pins::a3);
    DHT dht = DHT(pin, 11);
    hwlib::wait_ms(1200);

    while (true) {

        dht.sampleEnvironment();
        hwlib::cout << dht.getTemperature() << '\n';
        hwlib::wait_ms(2000);
    }

    return 0;
}