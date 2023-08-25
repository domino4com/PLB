#ifndef PLB_H
#define PLB_H

#include <ArduinoJson.h>
#include <Wire.h>

class PLB {
   public:
    PLB();
    bool begin();
    bool getData(float &, float &);
    bool getJSON(JsonObject &doc);
    float readVoltage();
    float readSOC();
    void reset();
    void setMaxVoltageAsCurrent();

   private:
    uint8_t _address;
    uint16_t readRegister(uint8_t reg);  
    void writeRegister(uint8_t reg, uint16_t value);
};
#endif  // PLB_H