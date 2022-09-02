//** CLIENT SCRIPT      **//
//** by Stach Redeker   **// 
//** 2022               **//

#include <SPI.h>
#include <DHT.h>
#include <ESP8266WiFi.h>

// Credentials of the WiFi network
char ssid[] = "SSID";
char pass[] = "PSSWRD";

// Connection settings
IPAddress server(192,168,178,155);       // the IP address of the server
WiFiClient client;

// DHT11 settings
#define DHTPIN 5 // WATCH OUT! THIS IS PIN D1 ON A ESP8266!
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE); // Initialize sensor

// Configuration settings
#define SLEEP_TIME 120 // time between measurements in seconds


void setup() {
  
  Serial.begin(115200);               
  
  WiFi.begin(ssid, pass);             

  Serial.println("Connecting to WiFi...");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }

  // DEBUGGING TOOLS
  Serial.println("Succesfully connected to WiFi");
  Serial.print("Status: ");            Serial.println(WiFi.status());   
  Serial.print("IP: ");                Serial.println(WiFi.localIP());
  Serial.print("MAC: ");               Serial.println(WiFi.macAddress()); 
  Serial.print("Subnet: ");            Serial.println(WiFi.subnetMask());
  Serial.print("Gateway: ");           Serial.println(WiFi.gatewayIP());
  Serial.print("SSID: ");              Serial.println(WiFi.SSID());
  Serial.print("Signal strength: ");   Serial.println(WiFi.RSSI());

  dht.begin();
  delay(2000);
  
}

void loop () {
  
  client.connect(server, 80);   // Connect to the server

  // GET SENSOR DATA
  float temperature = dht.readTemperature();

  Serial.println("BROADCASTING");
  Serial.print("TEM: ");             Serial.println(temperature);
  client.println(temperature);  // sends the message to the server
  client.println("\r");
  client.flush();
  
  delay((SLEEP_TIME)*1000);

}
