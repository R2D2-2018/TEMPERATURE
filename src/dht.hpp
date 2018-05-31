/**
 * @file DHT.hpp
 * @brief     DHT sensor class
 * @author    Michel Baartman
 * @license   See LICENSE
 */

#ifndef DHT_HPP
#define DHT_HPP

class DHT {
  private:
    int pinDATA; ///< DATA pin for DHT sensor

    int temperature; ///< Last environment temperature read
  public:
    /**
     * @brief DHT class constructor.
     *
     * The constructor for a DHT object.
     *
     * @param[in]    pinData     pinData is the code(int) of the pin that will be used to communicate with the sensor.
     * @return returns a DHT object
     */
    DHT(int pinData);

    /**
     * @brief returns the temperature variable of the DHT class.
     *
     * Returns the temperature variable within the DHT class. Current set to 10 by default.
     *
     * @return the read temperature as integer.
     */
    int getTemperature();

    /**
     * @brief returns the pinDATA variable of the DHT class.
     *
     * Returns the temperature variable within the DHT class. Current set to 10 by default.
     *
     * @return the pinDATA as integer.
     */
    int getPinDATA();
};

#endif // DHT_HPP
