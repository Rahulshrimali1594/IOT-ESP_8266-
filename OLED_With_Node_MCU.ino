// include two library for ssid1306 OLED Display // 


#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <SPI.h>

#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET); //define the OLED display and reset it 

void setup() {
  Serial.begin(9600); // define the baud rate // you can change it to 115200 
  
  // Initialize OLED display with SPI communication
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // Address 0x3C for 128x32
  
  // Clear the display buffer
  display.clearDisplay();
  
  // Set text size and color
  display.setTextSize(1);
  display.setTextColor(WHITE);
  
  // Display initial text
  display.setCursor(0, 0);
  display.println("Hello, ESP8266!");
  display.display();
}

void loop() {
  // Example: Displaying dynamic content
  display.clearDisplay();  // Clear the display buffer
  
  // Update text
  display.setCursor(0, 0);
  display.println("Time:");
  display.setCursor(0, 10);
  display.print("Millis: ");
  display.println(millis());
  
  // Refresh display
  display.display();
  
  delay(1000);  // Update every second
}
