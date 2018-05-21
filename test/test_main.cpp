#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
//#include "../src/DHT22.hpp"
#include "catch.hpp"

class DHT22 {
    private:
        int pinDATA;
        int temperature;
    public:
        DHT22(int pinData);
        int getTemperature();
        int getPinDATA();
};

DHT22::DHT22(int pinData) : pinDATA ( pinData ){
  temperature = 10;
}
int DHT22::getTemperature(){
    return temperature;
}
int DHT22::getPinDATA(){
    return pinDATA;
}

int pinDATA = 7;
DHT22 dht22(pinDATA);

TEST_CASE( "Example Test Case" ) {
    REQUIRE(10 == 10);
}

TEST_CASE( "DHT22 getTemperature" ) {
    REQUIRE(dht22.getTemperature() == 10);
}

TEST_CASE( "DHT22 Data Pin set" ) {
    REQUIRE(dht22.getPinDATA() == pinDATA);
}