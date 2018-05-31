#include "dht.hpp"
#include "wrap-hwlib.hpp"
#include <array>
#include <bitset>

// int pinRead(hwlib::target::pin_in_out pin);
int pinReadNew(hwlib::target::pin_in_out pin);
int printBits(uint8_t byte);

int main() {
    WDT->WDT_MR = WDT_MR_WDDIS;

    hwlib::wait_ms(1200);

    auto pin = hwlib::target::pin_in_out(hwlib::target::pins::a3);
    while (true) {
        pinReadNew(pin);
        hwlib::wait_ms(2000);
    }

    return 0;
}

int printBits(uint8_t byte) {
    for (int i = 8; i >= 0; i--) {
        hwlib::cout << ((byte >> i) & 1);
    }
    hwlib::cout << ' ' << int(byte) << '\n';
    return 0;
}

int pinReadNew(hwlib::target::pin_in_out pin) {
    hwlib::cout << "pinReadNew start\n";
    // set variables
    uint8_t data[5];
    int waitTime = 0;
    int timeOut = 8000;
    int bitTime = 0;
    int bitTimeCompare = 0;
    for (auto &byte : data) {
        byte = 0;
    }

    // send start command to dht
    pin.direction_set_output();
    pin.set(0);
    hwlib::wait_ms(20);
    pin.set(1);
    hwlib::wait_us(30);
    pin.direction_set_input();

    // wait for signal from dht
    waitTime = 0;
    while (pin.get() != 1) {
        if (waitTime >= timeOut) {
            return 0;
        }
        waitTime++;
    }
    while (pin.get() != 0) {
        if (waitTime >= timeOut) {
            return 0;
        }
        waitTime++;
    }

    // signal get, start grabbing bits
    for (auto &byte : data) {
        for (int b = 7; b >= 0; b--) {
            waitTime = 0;
            while (pin.get() != 1) {
                if (waitTime >= timeOut) {
                    return 0;
                }
                waitTime++;
            }

            waitTime = 0;
            bitTime = hwlib::now_us();
            while (pin.get() != 0) {
                if (waitTime >= timeOut) {
                    return 0;
                }
                waitTime++;
            }

            bitTimeCompare = hwlib::now_us();
            if ((bitTimeCompare - bitTime) > 40) {
                byte |= (1 << b);
            }
        }
    }

    for (const auto &byte : data) {
        printBits(byte);
    }

    hwlib::cout << "checking reads\n";
    printBits(data[0]);
    printBits(data[2]);
    printBits(data[0] + data[2]);
    printBits(data[0] + data[1] + data[2] + data[3]);
    printBits(data[4]);
    if ((data[0] + data[1] + data[2] + data[3]) == data[4]) {
        hwlib::cout << "read ok\n";
    }
    return 0;
}

// int pinRead(hwlib::target::pin_in_out pin) {
//     hwlib::cout << "pinRead()\n";
//     int timeOut = 8000;
//     int waitTime = 0;
//     int bitTime = 0;
//     int bitTimeCompare = 0;
//     int bitTimes[8];
//     std::array<uint8_t, 5> data = {0, 0, 0, 0, 0};
//     for (auto &byte : data) {
//         byte = 0;
//     }
//     // start transmission command
//     pin.direction_set_output();
//     pin.set(0);
//     hwlib::wait_ms(20);
//     pin.set(1);
//     hwlib::wait_us(30);
//     pin.direction_set_input();

//     waitTime = 0;
//     while (pin.get() != 1) {
//         if (waitTime >= timeOut) {
//             return 0;
//         }
//         waitTime++;
//     }
//     while (pin.get() != 0) {
//         if (waitTime >= timeOut) {
//             return 0;
//         }
//         waitTime++;
//     }

//     // obtaining the bits
//     for (auto &byte : data) {
//         for (int b = 0; b < 8; b++) {
//             waitTime = 0;
//             while (pin.get() != 1) {
//                 if (waitTime >= timeOut) {
//                     return 0;
//                 }
//                 waitTime++;
//             }

//             waitTime = 0;
//             bitTime = waitTime;
//             while (pin.get() != 0) {
//                 if (waitTime >= timeOut) {
//                     return 0;
//                 }
//                 waitTime++;
//             }

//             bitTimeCompare = waitTime;
//             // hwlib::cout << '\n' << waitTime << '\n';
//             if ((bitTimeCompare - bitTime) > 300) {
//                 byte |= (1 << b);
//             }
//             // bitTimes[b] = bitTimeCompare;
//         }
//     }

//     for (const auto &byte : data) {
//         printBits(byte);
//     }

//     uint8_t sum = data[0] + data[1] + data[2] + data[3];
//     hwlib::cout << '\n';
//     printBits(sum);
//     printBits(data[4]);
//     if (sum == data[4]) {
//         hwlib::cout << "correct read";
//     }

//     hwlib::cout << '\n';
//     return 0;
// }
