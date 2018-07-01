#define CATCH_CONFIG_MAIN // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "dht_11.hpp"
#include "dht_22.hpp"
#include "dht_mock.hpp"
#include "wrap-hwlib.hpp"

TEST_CASE("getTemperature DHTMock") {
    hwlib::test::pin_in_out<5 * 8, 5 * 8> test_pin_in_out{};
    test_pin_in_out.direction_set_output();
    DHTMock dht = DHTMock(test_pin_in_out);
    dht.setTemperature(20);
    dht.sampleEnvironment();
    REQUIRE(dht.getTemperature() == 20);
}

TEST_CASE("Tresholding") {
    hwlib::test::pin_in_out<14 * 8> pin;
    DHTMock dht = DHTMock(pin);
    dht.setTreshold(30);

    REQUIRE(dht.getTreshold() == 30);

    REQUIRE_FALSE(dht.checkTreshold());

    dht.setTemperature(31);
    REQUIRE(dht.checkTreshold());
}

TEST_CASE("negative value tresholding") {
    hwlib::test::pin_in_out<14 * 8> pin;
    DHTMock dht = DHTMock(pin);
    dht.setTreshold(-10);

    REQUIRE(dht.getTreshold() == -10);

    REQUIRE_FALSE(dht.checkTreshold());

    dht.setTemperature(-20);
    REQUIRE(dht.checkTreshold());
}

TEST_CASE("tresholding around zero") {
    hwlib::test::pin_in_out<14 * 8> pin;
    DHTMock dht = DHTMock(pin);
    dht.setTreshold(0);

    REQUIRE(dht.getTreshold() == 0);

    REQUIRE_FALSE(dht.checkTreshold());

    dht.setTemperature(5);
    REQUIRE(dht.checkTreshold());
}
