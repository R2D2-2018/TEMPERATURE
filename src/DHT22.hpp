/**
 * @file DHT22.hpp
 * @brief     DHT11 sensor class
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