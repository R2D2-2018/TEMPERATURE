#ifndef TEMPERATURE_HPP
#define TEMPERATURE_HPP
#include "wrap-hwlib.hpp"

class Temperature {
  private:
    int treshold;
    int temperature;

  public:
    Temperature();
    virtual int getTemperature() = 0;
    void setTreshold(int treshold);
    int getTreshold();
    bool checkTreshold();
};

#endif // TEMPERATURE_HPP