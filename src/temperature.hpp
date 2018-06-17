/**
 * @file
 * @brief     The temperature base class that is an interface for all temperature sensors.
 * @author    Jari van Dam
 * @license   See LICENSE
 */
#ifndef TEMPERATURE_HPP
#define TEMPERATURE_HPP

class Temperature {
  private:
    int treshold; ///< threshold value to check if treshold is exceeded.

  protected:
    int temperature; ///< the last measured temperature.

  public:
    /**
     * @brief Default constructor for Temperature base class.
     *
     */
    Temperature();
    /**
     * @brief Interface to get the current temperature from the sensor.
     *
     * @return Int temperature the current temperature messured, decimals are left away so no rounding.
     */
    virtual int getTemperature() = 0;
    /**
     * @brief Set the treshold value
     *
     * @param[in]     treshold Trehshold value.
     */
    void setTreshold(int treshold);
    /**
     * @brief Get the set treshold.
     *
     * @return The set treshold value.
     */
    int getTreshold();
    /**
     * @brief Check if current sensor value is above treshold.
     *
     * @return Always returns false, no mather what the treshold or sensor value is.
     */
    bool checkTreshold();
};

#endif // TEMPERATURE_HPP