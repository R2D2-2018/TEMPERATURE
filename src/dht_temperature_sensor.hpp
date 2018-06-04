/**
 * @file DHT.hpp
 * @brief     DHT sensor class
 * @author    Michel Baartman
 * @license   See LICENSE
 */

#ifndef DHT_HPP
#define DHT_HPP

#include "wrap-hwlib.hpp"

class DHT {
  private:
    hwlib::pin_in_out &pin; ///< DATA pin for DHT sensor
    int temperature;        ///< Last environment temperature read
    int version;            ///< dht sensor version
    uint8_t data[5];        ///< data bytes sampled from sensor

    /**
     * @brief Checks the current data arrays.
     *
     * Checks the current data arrays and compares them with eachother to see whether the data is correct/reliable or not.
     *
     * @return returns reliability of data as boolean. true/1 = data reliable. false/0 = data unreliable.
     */
    bool checksum();

    /**
     * @brief Sends a predefined cmd through a single wire transmission.
     *
     * Sends a predefined command through single wire transmission.
     * The following commands are available:
     * 'r' - sends a bit to request data.
     *
     * @param[in]    cmd    cmd is a single char that has a write/send protocol attached to it within the function.
     */
    void dhtWrite(char cmd);

    /**
     * @brief read protocol for the dht sensor
     *
     * a function that starts the read protocol for the dht sensor.
     *
     * @return returns a int whether the reading was succesful. 1 = succeeded. 0 = timed out. In the future more int values can be
     * used for more specific troubleshooting such as -1.
     */
    int dhtRead();

    /**
     * @brief get bits protocol part of the read protocol
     *
     * a function that contains the bit signal protocol of the part of the entire read protocol.
     *
     * @return returns a int whether the checksum() was succesful. 1 = succeeded. 0 = timed out. In the future more int values can
     * be used for more specific troubleshooting such as -1.
     */
    int dhtGetBits();

    /**
     * @brief wait protocol part of the read protocol
     *
     * a function that waits until it gets a start signal/bit from the sensor.
     *
     * @return returns a int whether the start was obtained. 1 = succeeded. 0 = timed out. In the future more int values can be used
     * for more specific troubleshooting such as -1.
     */
    int dhtWait();

  public:
    /**
     * @brief DHT class constructor.
     *
     * The constructor for a DHT object. For more information about the DHT11 sensor:
     * https://akizukidenshi.com/download/ds/aosong/DHT11.pdf
     *
     * @param[in]    pinData    pinData a hwlib::pin_in_out object. this is our single-wire communication to the sensor.
     * @param[in]    version    version is an int that resembles the version of the DHT. DHT11 is the only one functioning as of
     * now.
     *
     * @return returns a DHT object
     */
    DHT(hwlib::pin_in_out &pinData, int version);

    /**
     * @brief Returns the temperature variable of the DHT class.
     *
     * Returns the temperature variable within the DHT class. Current set to 0 by default.
     * Temperature for the DHT11 sensor are the data[2] bytes at high temperature and data[3] bytes at low.
     *
     * @return Environment temperature as integer.
     */
    int getTemperature();

    /**
     * @brief Samples the environment.
     *
     * Requests a communication with the sensor and fills the data arrays resembling bytes and the temperature variable.
     */
    void sampleEnvironment();
};

#endif // DHT_HPP
