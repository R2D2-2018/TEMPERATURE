#ifndef DHT_HPP
#define DHT_HPP
#include "temperature.hpp"
#include "wrap-hwlib.hpp"
class DHT : public Temperature {
  protected:
    int temperature;        ///< Last environment temperature read
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
    DHT(hwlib::pin_in_out &pinData);
    virtual void sampleEnvironment() = 0;
    int getTemperature();
};

#endif // DHT_HPP