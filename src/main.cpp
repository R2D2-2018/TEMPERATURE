#include "dht22.hpp"
#include "wrap-hwlib.hpp"
#include <array>

int read(hwlib::target::pin_in_out pin);

int main() {
    WDT->WDT_MR = WDT_MR_WDDIS;

    hwlib::wait_ms(1200);
    auto pin = hwlib::target::pin_in_out(hwlib::target::pins::a3);
    while(true){
        read(pin);
        hwlib::wait_ms(2000);
    }

    return 0;
}

int read(hwlib::target::pin_in_out pin){
    /// set variables
    int timeOut = 8000;
    int waitTime = 0;
    long bitTime = 0;
    long bitTimeCompare = 0;
    pin.refresh(); pin.flush();
    int data[5][8];
    std::array<int, 5> data2 = {5, 4, 3, 2, 1};
    for(int i = 0; i < 5; i++){
        for(int b = 0; b < 8; b++){
            data[i][b] = 0; 
        }
    }

    /// send start transmission signal
	pin.direction_set_output();
	pin.set(0); 
	hwlib::wait_ms(20); 
	pin.set(1); 
	hwlib::wait_us(30); 
	pin.direction_set_input(); 

    /// wait for dht sensor signal
	waitTime = 0;
	while(pin.get() != 1){ 
        if(waitTime >= timeOut){ return 0; } 
        waitTime++;
    }
	while(pin.get() != 0){ 
        if(waitTime >= timeOut){ return 0; }
        waitTime++;
    }

    /// obtaining the bits
    for(int i = 0; i < 5; i++){
        for(int b = 0; b < 8; b++){
            waitTime = 0;
            while(pin.get() != 1){
                if(waitTime >= timeOut){ return 0; }
                waitTime++;
            }

            waitTime = 0;
            bitTime = hwlib::now_us();
            while(pin.get() != 0){
                if(waitTime >= timeOut){ return 0; }
                waitTime++;
            }

            bitTimeCompare = hwlib::now_us();
            if((bitTimeCompare - bitTime) > 30){
                data[i][b] = 1;
            }
        }
	}

    /// printing data
    for(int i = 0; i < 5; i++){
        for(int b = 0; b < 8; b++){
            hwlib::cout << int(data[i][b]);
        }
        hwlib::cout << ' ';
    }
    
    /// checksum
    // uint32_t sum = 0;
    // for(int i = 0; i < 5; i++){
    //     hwlib::cout << data2[i];
    // }

    hwlib::cout << "\n";
    return 0;
}