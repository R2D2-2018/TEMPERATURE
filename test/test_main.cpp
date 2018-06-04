#define CATCH_CONFIG_MAIN // This tells Catch to provide a main() - only do this in one cpp file
#include "../src/dht_temperature_sensor.hpp"
#include "catch.hpp"
#include "wrap-hwlib.hpp"

TEST_CASE("getTemperature") {
    hwlib::test::pin_in_out<14 * 8> pin;
    DHT dht = DHT(pin, 11);
    dht.sampleEnvironment();
    REQUIRE(dht.getTemperature() == 0);
}