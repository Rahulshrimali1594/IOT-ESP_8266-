#include <ESP8266WiFi.h>
#include <DHT.h>
#include <URLEncode.h>

#define DHTPIN D3  // Pin connected to DHT11 Data pin
#define DHTTYPE DHT11

const char* ssid = "YOUR_SSID";        // Replace with your Wi-Fi SSID
const char* password = "YOUR_PASSWORD"; // Replace with your Wi-Fi password

const char* apiUrl = "http://api.callmebot.com/whatsapp.php";
const char* phoneNumber = "YOUR_PHONE_NUMBER"; // WhatsApp number in format +1234567890
const char* apiKey = "YOUR_API_KEY"; // CallMeBot API key

DHT dht(DHTPIN, DHTTYPE);
WiFiClient client;

void setup() {
  Serial.begin(115200);
  delay(10);

  dht.begin();

  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");  
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

void loop() {
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  if (isnan(h) || isnan(t)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  Serial.print("Humidity: ");
  Serial.print(h);
  Serial.print(" %\t");
  Serial.print("Temperature: ");
  Serial.print(t);
  Serial.println(" *C ");

  if (t > 30) { // Set your threshold temperature
    sendWhatsAppMessage(t, h);
  }

  delay(60000); // Wait a minute between readings
}

void sendWhatsAppMessage(float temperature, float humidity) {
  String message = "Temperature Alert!\nTemperature: " + String(temperature) + " *C\nHumidity: " + String(humidity) + " %";
  String url = String(apiUrl) + "?phone=" + String(phoneNumber) + "&text=" + urlencode(message) + "&apikey=" + String(apiKey);

  if (client.connect("api.callmebot.com", 80)) {
    client.print(String("GET ") + url + " HTTP/1.1\r\n" +
                 "Host: api.callmebot.com\r\n" +
                 "Connection: close\r\n\r\n");
    Serial.println("WhatsApp message sent");
  } else {
    Serial.println("Connection failed");
  }
}
