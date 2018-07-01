/**
 * @file DHT.hpp
 * @brief     DHT sensor class
 * @author    Jari van Dam
 * @license   See LICENSE
 */

#ifndef DHT_Mock_HPP
#define DHT_Mock_HPP

#include "dht.hpp"
#include "wrap-hwlib.hpp"

class DHTMock : public DHT {
  private:
    int desireTemperature;

  public:
    /**
     * @brief DHT class constructor.
     *
     * The constructor for a DHT object.
     *
     * @param[in]    pinData    pinData a hwlib::pin_in_out object. this is our single-wire communication to the sensor.
     *
     * @return returns a DHT object
     */
    DHTMock(hwlib::pin_in_out &pinData);

    /**
     * @brief Samples the environment.
     *
     * Requests a communication with the sensor and fills the data arrays resembling bytes and the temperature variable.
     */
    void sampleEnvironment();

    /**
     * @brief Sets desireTemperature and temperature variable to temp
     *
     * @param[in]     temp    An integer representing a measured temperature
     */
    void setTemperature(int temp);
};

#endif // DHT22_HPP
