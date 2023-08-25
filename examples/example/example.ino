#include <ArduinoJson.h>
#include <Wire.h>
#ifndef I2C_SDA
#define I2C_SDA SDA
#endif
#ifndef I2C_SCL
#define I2C_SCL SCL
#endif

// Specifics
#include <PLB.h>
PLB input;
float var1, var2;
char s[] = "Voltage: %.2f, State of Charge: %.2f\n";


void setup() {
    Serial.begin(115200);
    delay(1000);
    Serial.printf("\nPLB Example Test\n");

    Wire.setPins(I2C_SDA, I2C_SCL);
    Wire.begin();

    if (input.begin()) {
        Serial.println("PLB initialized successfully.");
    } else {
        Serial.println("Failed to initialize PLB!");
        exit(0);
    }

    input.setMaxVoltageAsCurrent(); // Call if fresh battery is inserted
}

void loop() {
    if (input.getData(var1, var2)) {
        Serial.printf(s, var1, var2);
    } else {
        Serial.println("Failed to get PLB data.");
    }

    delay(1000);
}