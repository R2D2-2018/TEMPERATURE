#define CATCH_CONFIG_MAIN // This tells Catch to provide a main() - only do this in one cpp file
#include "../src/dht.hpp"
#include "catch.hpp"
#include "wrap-hwlib.hpp"

TEST_CASE("Example Test Case") {
    REQUIRE(10 == 10);
}

TEST_CASE("dhtReadWait") {
    hwlib::test::pin_in_out<14 * 8> pin;
    DHT dht = DHT(pin, 11);
    REQUIRE(dht.dhtReadWait() == 1);
}

TEST_CASE("dhtReadGetBits") {
    hwlib::test::pin_in_out<14 * 8> pin;
    DHT dht = DHT(pin, 11);
    REQUIRE(dht.dhtReadGetBits() == 1);
}

TEST_CASE("checksum") {
    hwlib::test::pin_in_out<14 * 8> pin;
    DHT dht = DHT(pin, 11);
    REQUIRE(dht.checksum() == 1);
}

TEST_CASE("getTemperature") {
    hwlib::test::pin_in_out<14 * 8> pin;
    DHT dht = DHT(pin, 11);
    REQUIRE(dht.getTemperature() == 0);
}