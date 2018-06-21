/**
 * @file
 * @brief     The base class for all DHT temperature sensors.
 * @author    Jari van Dam
 * @license   See LICENSE
 */
#ifndef DHT_HPP
#define DHT_HPP
#include "temperature.hpp"
#include "wrap-hwlib.hpp"
class DHT : public Temperature {
  protected:
    uint8_t data[5];        ///< data bytes sampled from sensor
    hwlib::pin_in_out &pin; ///< DATA pin for DHT sensor
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
     * @return returns a int whether the checksum() was succesful. 1 = succeeded. 0 = timed out. In the future more int values
     * can be used for more specific troubleshooting such as -1.
     */
    int dhtGetBits();

    /**
     * @brief wait protocol part of the read protocol
     *
     * a function that waits until it gets a start signal/bit from the sensor.
     *
     * @return Returns a 0 when no bits a detected. Else the time between the bits is returned.
     */
    int dhtWait();

  public:
    /**
     * @brief The default constructor for the DHT class.
     *
     * @param[in]     pinData   The data pin of the DHT sensor.
     */
    DHT(hwlib::pin_in_out &pinData);
    /**
     * @brief Virtual function that will get the data from the DHT sensor.
     *
     */
    virtual void sampleEnvironment() = 0;
    /**
     * @brief Get the current temperature of the sensor.
     *
     * @return The temperature as in int, decimals are left away and not rounded.
     */
    int getTemperature();
};

#endif // DHT_HPP