#include "dht22.hpp"
#include "wrap-hwlib.hpp"

int read(hwlib::target::pin_in_out pin);

int main() {
    WDT->WDT_MR = WDT_MR_WDDIS;

    hwlib::wait_ms(1200);
    auto pin = hwlib::target::pin_in_out(hwlib::target::pins::a0);
    while(true){
        read(pin);
        hwlib::wait_ms(2000);
    }

    return 0;
}

int read(hwlib::target::pin_in_out pin){
    


    pin.direction_set_output();
    int waitTime = 0;
    int bit = 0;
    int byte = 1;
    pin.set(0);
    hwlib::wait_ms(20);
    pin.set(1);
    hwlib::wait_us(20);
    pin.direction_set_input();
    while(pin.get() != 0){}
    //hwlib::cout << "start communication\n";
    while(pin.get() != 1){}
    while(true){
        while(pin.get() != 0){
            waitTime ++;
            hwlib::wait_us(1);
            if(waitTime > 90){ hwlib::cout << "time out"; return 0; }
        }
        if(waitTime > 30){
            bit = 1;
        } else { 
            bit = 0;
        }
        byte = (byte*10)+bit;
        if(byte > 100000){
            hwlib::cout << byte;
            return 0;
        }
    }
    return 0;
}