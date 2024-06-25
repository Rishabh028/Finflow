#include <Adafruit_GFX.h>
#include <Adafruit_SSD1351.h>
#include <SPI.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 128

#define OLED_DC    9
#define OLED_CS    10
#define OLED_RESET 8

Adafruit_SSD1351 display = Adafruit_SSD1351(SCREEN_WIDTH, SCREEN_HEIGHT, &SPI, OLED_DC, OLED_RESET, OLED_CS);

void setup() {
  Serial.begin(9600); // initialize serial communication at 9600 baud

  display.begin(0x3D); // Initialize the OLED display
  display.fillScreen(0x0000); // Fill the screen with black
  delay(1000);
}

void loop() {
  Serial.println("Hello, world!"); // print "Hello, world!" to the serial monitor
  delay(1000); // wait for 1 second

  // Read from Serial Monitor
  if (Serial.available() > 0) {
    String serialData = Serial.readString();

    // Display on the OLED
    display.fillScreen(0x0000);  // Clear the display
    display.setCursor(0, 0);
    display.setTextSize(1);
    display.setTextColor(0xFFFF);  // White color
    display.println(serialData);
    display.display();  // Update the display
  }

  Serial.flush();  // Clear the serial buffer
  delay(100);  // Adjust delay as needed
}
