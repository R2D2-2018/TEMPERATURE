#include "dht22.hpp"
#include "wrap-hwlib.hpp"

int main() {
    WDT->WDT_MR = WDT_MR_WDDIS;

    hwlib::cout << "setup pins\n";
    hwlib::wait_ms(1100);
    //auto pin = hwlib::target::pin_in(hwlib::target::pins::d24);
    auto pin = hwlib::target::pin_in_out(hwlib::target::pins::d7);
    hwlib::wait_ms(1100);
    DHT22 dht22(24);

    //uint16_t data = 0;
    //int waitTime = 0;

    while(true){
        pin.direction_set_output();
        //hwlib::cout << "set start bit\n";
        pin.set(0);
        hwlib::wait_ms(20);
        pin.set(1);
        pin.direction_set_input();
        while(pin.get() == 1){
            hwlib::cout << "waiting\n";
            hwlib::wait_us(10);
        }
        hwlib::cout << "start transmission\n";
        while(true){
        }
        //pin.refresh();
        //hwlib::wait_ms(18);
        //pin.flush();
        //hwlib::wait_ms(1100);
        //pin = hwlib::target::pin_in(hwlib::target::pins::d24);
        // while(true){
        //     if(pin.get() == 0){
        //         hwlib::cout << "0";
        //     }
        //     //hwlib::cout << pin.get();
        //     //hwlib::wait_us(1);
        //     //hwlib::wait_ms(100);
        // }
        // int waitTime;
        // for(int i = 0; i < 8; i++){
        //     waitTime = 0;
        //     while(pin.get() == 1){}
        //     waitTime ++;
        // }
    }

    return 0;
}