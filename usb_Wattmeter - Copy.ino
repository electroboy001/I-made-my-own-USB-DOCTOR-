// Suitable with 12v battery, adaptor wattage, current and voltage monitoring.
// Resistor divider network need more upgradation if voltage is higher that 15.6
// Try 0x3f OLED address if screen did not work.
// Precision of the voltage depends on the tolerance of the resistors.

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define OLED_RESET -1
Adafruit_SSD1306 display(128, 32, &Wire, OLED_RESET);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C); // Change the address to your's one
  display.clearDisplay();
}

void loop() {
  // put your main code here, to run repeatedly:
  int adc = analogRead(A0);// current
  int adc2 = analogRead(A1); //voltage
  float voltage = adc * 5 / 1023.0;           // Currrent value... Both ADC values converted into voltages 
  float voltage2 = adc2 * 16.24/1023.0;       // Volatge value... resistor divider basics needed to be learn 
  float current = (voltage - 2.5) / 0.66;     // ACS712 5A 0.66 FOR 20A 0.100 (-2.5 becasue Vout of 712 changes WRT 2.50)

// change the 16.24 value a little bit to get the proper calibration

  if (current < 0.16) {
    current = 0;
  }
  
   display.clearDisplay();
   display.setTextSize(1);
   display.setTextColor(WHITE);
   
   display.setCursor(10,00);
   display.print("Voltage : ");
   display.print(voltage2);
   display.display();

   display.setCursor(10,10);
   display.print("Current : ");
   display.print(current);
   display.display();


   display.setCursor(10,20);
   display.print("Power : ");
   display.print(current*voltage);
   display.display();

   display.setCursor(110,15);
   display.print("USB");
   display.setCursor(110,25);
   display.print("DOC");
   display.display();
   
   delay(1000);
}
