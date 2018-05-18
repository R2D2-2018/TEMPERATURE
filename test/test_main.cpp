#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "../src/DHT22.hpp"

TEST_CASE( "Example Test Case" ) {
    REQUIRE(10 == 10);
}

TEST_CASE( "dht22-sensor-class temperature function" ) {
    DHT22 dht22(7);
    REQUIRE(dht22.getTemperature() == 10);
}

TEST_CASE( "dht22-sensor-class pinDATA" ) {
    int pinDATA = 7;
    DHT22 dht22(pinDATA);
    REQUIRE(dht22.getPinDATA() == pinDATA);
}