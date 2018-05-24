/**
 * @file dht22.hpp
 * @brief     DHT22 sensor class
 * @author    Michel Baartman
 * @license   See LICENSE
 */

#ifndef DHT22_HPP
#define DHT22_HPP

class DHT22 {
  private:
    int pinDATA; ///< DATA pin for DHT22 sensor

    int temperature; ///< Last environment temperature read
  public:
    /**
     * @brief DHT22 class constructor.
     *
     * The constructor for a DHT22 object.
     *
     * @param[in]    pinData     pinData is the code(int) of the pin that will be used to communicate with the sensor.
     * @return returns a DHT22 object
     */
    DHT22(int pinData);

    /**
     * @brief returns the temperature variable of the DHT22 class.
     *
     * Returns the temperature variable within the DHT22 class. Current set to 10 by default.
     *
     * @return the read temperature as integer.
     */
    int getTemperature();

    /**
     * @brief returns the pinDATA variable of the DHT22 class.
     *
     * Returns the temperature variable within the DHT22 class. Current set to 10 by default.
     *
     * @return the pinDATA as integer.
     */
    int getPinDATA();
};

#endif // DHT22_HPP
