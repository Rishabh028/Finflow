#include <Arduino.h>
 
#define VREF    5000//VREF(mv)
#define ADC_RES 1024//ADC Resolution
 
uint32_t raw;
 
void setup()
{
    Serial.begin(115200);
}
 
void loop()
{
    raw=analogRead(A1);
    Serial.println("raw:\t"+String(raw)+"\tVoltage(mv)"+String(raw*VREF/ADC_RES));
    delay(1000);
}