#define CATCH_CONFIG_MAIN // This tells Catch to provide a main() - only do this in one cpp file
#include "../src/dht_11.hpp"
#include "../src/dht_22.hpp"
#include "catch.hpp"
#include "wrap-hwlib.hpp"

TEST_CASE("getTemperature DHT22") {
    hwlib::test::pin_in_out<14 * 8> pin;
    DHT22 dht = DHT22(pin);
    dht.sampleEnvironment();
    REQUIRE(dht.getTemperature() == 0);
}

TEST_CASE("getTemperature DHT11") {
    hwlib::test::pin_in_out<14 * 8> pin;
    DHT11 dht = DHT11(pin);
    dht.sampleEnvironment();
    REQUIRE(dht.getTemperature() == 0);
}
