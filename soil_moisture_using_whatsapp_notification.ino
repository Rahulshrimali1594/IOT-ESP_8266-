#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClient.h>
#include <UrlEncode.h>

const char* ssid = "";
const char* password = "";
// add +iternational_country_code + phone number
// India +91, example 12345678910
String phoneNumber = "";
String apiKey = ""; // enter your API key which is recieved by chatbot of whatsapp
const int sensor_pin = A0;
void sendMessage(String message)
{

  // Data to send with HTTP POST
  String url = "http://api.callmebot.com/whatsapp.php?phone=" + phoneNumber + "&apikey=" + apiKey + "&text=" + urlEncode(message);
  WiFiClient client;    
  HTTPClient http;
  http.begin(client, url);

  // Specify content-type header
  http.addHeader("Content-Type", "application/x-www-form-urlencoded");
  
  // Send HTTP POST request
  int httpResponseCode = http.POST(url);
  if (httpResponseCode == 200){
    Serial.println("Message sent successfully");
  }
  else{
    Serial.println("Error sending the message");
    Serial.print("HTTP response code: ");
    Serial.println(httpResponseCode);
  }

  // Free resources
  http.end();
}/* Connect Soil moisture analog sensor pin to A0 of NodeMCU */
void setup() {
  Serial.begin(9600); 
   pinMode(sensor_pin, INPUT);
   WiFi.begin(ssid, password);
  Serial.println("Connecting");
  while(WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to WiFi network with IP Address: ");
  Serial.println(WiFi.localIP());
  /* Define baud rate for serial communication */
}

void loop() {
  float moisture_percentage;
  moisture_percentage = ( 100.00 - ( (analogRead(sensor_pin)/1023.00) * 100.00 ) );

  Serial.print("Soil Moisture(in Percentage) = ");
  Serial.print(soil is dry);
  Serial.println("%");
  sendMessage("Soil Moisture(in Percentage) = " + String(moisture_percentage));
  delay(5000);
}