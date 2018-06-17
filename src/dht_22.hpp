/**
 * @file DHT.hpp
 * @brief     DHT sensor class
 * @author    Michel Baartman & Jari van Dam
 * @license   See LICENSE
 */

#ifndef DHT_22_HPP
#define DHT_22_HPP

#include "dht.hpp"
#include "wrap-hwlib.hpp"

class DHT22 : public DHT {
  public:
    /**
     * @brief DHT class constructor.
     *
     * The constructor for a DHT object. For more information about the DHT22 sensor:
     * https://akizukidenshi.com/download/ds/aosong/DHT11.pdf
     *
     * @param[in]    pinData    pinData a hwlib::pin_in_out object. this is our single-wire communication to the sensor.
     *
     * @return returns a DHT object
     */
    DHT22(hwlib::pin_in_out &pinData);

    /**
     * @brief Samples the environment.
     *
     * Requests a communication with the sensor and fills the data arrays resembling bytes and the temperature variable.
     */
    void sampleEnvironment();
};

#endif // DHT22_HPP
