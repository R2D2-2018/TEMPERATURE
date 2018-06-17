/**
 * @file DHT.hpp
 * @brief     DHT sensor class
 * @author    Michel Baartman & jari van Dam
 * @license   See LICENSE
 */

#ifndef DHT_11_HPP
#define DHT_11_HPP

#include "dht.hpp"
#include "wrap-hwlib.hpp"

class DHT11 : public DHT {
  public:
    /**
     * @brief Default constructor for DHT11 sensor.
     *
     * @param[in]     pinData    The hwlib::pin_in_out object for the dataPin of DHT11.
     */
    DHT11(hwlib::pin_in_out &pinData);
    /**
     * @brief Samples the environment.
     *
     * Requests a communication with the sensor and fills the data arrays resembling bytes and the temperature variable.
     */
    void sampleEnvironment();
};

#endif // DHT_11_HPP
