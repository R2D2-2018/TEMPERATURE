#include "dht22.hpp"
#include "wrap-hwlib.hpp"

int read(hwlib::target::pin_in_out pin);

int main() {
    WDT->WDT_MR = WDT_MR_WDDIS;

    hwlib::wait_ms(1200);
    auto pin = due::pin_in_out(due::pins::a0);
    while(true){
        read(pin);
        hwlib::wait_ms(2000);
    }

    return 0;
}

int read(due::pin_in_out pin){
    int waitTime1 = 0;
    int waitTime2 = 0;
    pin.refresh(); pin.flush();
    // start transmission command
    pin.direction_set_output();
    pin.set(0);
    hwlib::wait_ms(18);
    pin.set(1);
    pin.direction_set_input();
    //hwlib::wait_us(20);

    //waiting for transmittion from DHT11
    while(pin.get() != 0){ waitTime1 ++; }
    while(pin.get() != 1){ waitTime2 ++; }
    hwlib::cout << "\n" << waitTime1 << "-" << waitTime2 << "\n";
    hwlib::cout << "start transmission\n";

    waitTime1 = 0;
    while(waitTime1 < 40){
        hwlib::cout << pin.get();
        waitTime1 ++;
    }

    // int count = 0;
    // while(count < 8){
    //     while(true){
    //         //hwlib::cout << "bit " << count;
    //         waitTime = 0;
    //         while(pin.get() != 0){}
    //         while(pin.get() != 1){
    //             waitTime++;
    //             hwlib::cout << "waiting";
    //             hwlib::wait_us(1);
    //         }
    //         if(waitTime > 40){
    //             hwlib::cout << "0";
    //             break;
    //         }
    //         hwlib::cout << "1";
    //         break;
    //         //hwlib::cout << "bit got";
    //     }
    //     count++;
    // }
    return 0;
}