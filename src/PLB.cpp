/*!
 * @file PLB.cpp
 * @brief Get data from PLB
 * @n ...
 * @copyright   MIT License
 * @author [Bjarke Gotfredsen](bjarke@gotfredsen.com)
 * @version  V1.0
 * @date  2023
 * @https://github.com/domino4com/PLB
 */
#include "PLB.h"

#define VCELL_REG 0x02
#define SOC_REG 0x04
#define COMMAND_REG 0xFE
#define MODE_REG     0x06
#define FULLSOC_REG  0x10
#define PLB_ADDRESS (uint8_t)0x36

PLB::PLB() {
}

bool PLB::begin() {
    return true;
}

bool PLB::getData(float &var1, float &var2) {
    var1 = readVoltage();
    var2 = readSOC();

    return true;  // Return true for successful read (add error handling if needed)
}

bool PLB::getJSON(JsonObject &doc) {
    float var1, var2;
    if (!getData(var1, var2)) {
        return false;
    }

    JsonArray dataArray = doc.createNestedArray("PLB");

    JsonObject dataSet = dataArray.createNestedObject();  // First data set
    dataSet["name"] = "Voltage";
    dataSet["value"] = var1;
    dataSet["unit"] = "V";

    dataSet = dataArray.createNestedObject();  // Subsequent data sets
    dataSet["name"] = "State of Charge";
    dataSet["value"] = var2;
    dataSet["unit"] = "%";

    return true;
}

float PLB::readVoltage() {
    uint16_t vCell = readRegister(VCELL_REG);
    // return vCell * 0.00125;  // 1.25 mV per LSB
    return vCell * 0.000078125;                      // MAX17048 VCELL is 16-bit, 78.125uV/cell per LSB
}

float PLB::readSOC() {
    uint16_t soc = readRegister(SOC_REG);
    return soc * 0.00390625;  // Percentage (SOC)
}

void PLB::setMaxVoltageAsCurrent()
{
  uint16_t vCell = readRegister(VCELL_REG); // Read current voltage
  writeRegister(FULLSOC_REG, vCell); // Set as max voltage
}

void PLB::reset() {
    Wire.beginTransmission(PLB_ADDRESS);
    Wire.write(COMMAND_REG);
    Wire.write(0x54);
    Wire.write(0x00);
    Wire.endTransmission();
}

uint16_t PLB::readRegister(uint8_t reg) {
    Wire.beginTransmission(PLB_ADDRESS);
    Wire.write(reg);
    Wire.endTransmission();
    Wire.requestFrom(PLB_ADDRESS, (uint8_t)2);
    return (Wire.read() << 8) | Wire.read();
}

void PLB::writeRegister(uint8_t reg, uint16_t value)
{
  Wire.beginTransmission(_address);
  Wire.write(reg);
  Wire.write((value >> 8) & 0xFF);
  Wire.write(value & 0xFF);
  Wire.endTransmission();
}
