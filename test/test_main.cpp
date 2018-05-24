#define CATCH_CONFIG_MAIN // This tells Catch to provide a main() - only do this in one cpp file
#include "../src/dht22.hpp"
#include "catch.hpp"

int pinDATA = 7;
DHT22 dht22(pinDATA);

TEST_CASE("Example Test Case") {
    REQUIRE(10 == 10);
}

TEST_CASE("DHT22 getTemperature") {
    REQUIRE(dht22.getTemperature() == 10);
}

TEST_CASE("DHT22 Data Pin set") {
    REQUIRE(dht22.getPinDATA() == pinDATA);
}