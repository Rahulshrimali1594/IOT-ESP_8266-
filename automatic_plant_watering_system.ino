#include <LiquidCrystal_I2C.h>
#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

//Initialize the LCD display with I2C device address 0x27 .
LiquidCrystal_I2C lcd(0x27, 16, 2); 

char auth[] = "";//Enter your Auth token
char ssid[] = "";//Enter your WIFI name
char pass[] = "";//Enter your WIFI password

BlynkTimer timer;
bool Relay = 0;

//Define component pins
#define sensor A0 // define the pin for soil moisture sensor 
#define waterPump D3 // define the pin for water pump

void setup() 
{
    // Initialize Serial communication
    Serial.begin(9600);

    // Initialize components
    pinMode(waterPump, OUTPUT);
    pinMode(sensor, INPUT);
    lcd.init();
    lcd.backlight();

    // Attempt Blynk connection
    Blynk.begin(auth, ssid, pass, "blynk.cloud", 80);
    if (!Blynk.connect()) {
        Serial.println("Failed to connect to Blynk server");
        while (1) {
            // Add error handling actions here
        }
    }

    // Wait for Blynk to stabilize
    delay(1000);

    // Start periodic sensor reading
    timer.setInterval(100L, soilMoistureSensor);
}

void loop() {
    // Run Blynk and timer-related functions
    Blynk.run();
    timer.run();

    // Add non-blocking tasks or additional functionality here
}

void soilMoistureSensor() {
    // Read soil moisture sensor
    int value = analogRead(sensor);
    value = map(value, 0, 1024, 0, 100);
    value = (value - 100) * -1;

    // Update Blynk and LCD
    Blynk.virtualWrite(V0, value);
    lcd.setCursor(0, 0);
    lcd.print("Moisture :");
    lcd.print(value);
    lcd.print(" ");
}
