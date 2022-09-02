//** SERVER SCRIPT      **//
//** by Stach Redeker   **// 
//** 2022               **//


#include <SPI.h>
#include <ESP8266WiFi.h>
#include <LiquidCrystal.h>

// Credentials of the WiFi network
char ssid[] = "SSID";
char pass[] = "PSSWRD";
WiFiServer server(80);                    

// Connection settings
IPAddress ip(192, 168, 178, 155);            // wanted IP address of the server
IPAddress gateway(192,168,178,1);           // gateway of the WiFi network --> see router, or router's manual
IPAddress subnet(255,255,255,0);          // subnet mask of Wifi network --> see router settings, or router's manual

// LCD SCREEN
#define LCD4 2  // D4
#define LCD5 14 // D5
#define LCD6 12 // D6
#define LCD7 13 // D7
#define LCDrs 0 // D3
#define LCDe 4 //  D2

LiquidCrystal lcd(LCDrs, LCDe, LCD4, LCD5, LCD6, LCD7);

void setup() {

  lcd.begin(16, 2); //size of the display
  lcd.setCursor(0, 0);
  lcd.print("WiFi TEMP");
  lcd.setCursor(0, 1);
  lcd.print("INITIALIZING");
  
  Serial.begin(115200);
  
  WiFi.config(ip, gateway, subnet);       // forces to use the set IP
  WiFi.begin(ssid, pass);                 // connecting to the WiFi router

  Serial.println("Connecting to WiFi...");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  
  server.begin();
  
  // DEBUGGING TOOLS
  Serial.println("Succesfully connected to WiFi");
  Serial.print("Status: ");            Serial.println(WiFi.status());   
  Serial.print("IP: ");                Serial.println(WiFi.localIP());
  Serial.print("MAC: ");               Serial.println(WiFi.macAddress()); 
  Serial.print("Subnet: ");            Serial.println(WiFi.subnetMask());
  Serial.print("Gateway: ");           Serial.println(WiFi.gatewayIP());
  Serial.print("SSID: ");              Serial.println(WiFi.SSID());
  Serial.print("Signal strength: ");   Serial.println(WiFi.RSSI());

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("IP:");
  lcd.setCursor(0, 1);
  lcd.print(WiFi.localIP());

  delay(4000);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("MAC:");
  lcd.setCursor(0, 1);
  lcd.print(WiFi.macAddress());

  delay(4000);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("TEMPERATURE:");
  
}

void loop () {
  
  WiFiClient client = server.available();
  
  if (client) {
    if (client.connected()) {
      Serial.println("Receiving data");
      String temperature = client.readStringUntil('\r');    // receives the message from the client
      Serial.print("TEM: "); Serial.println(temperature);
      client.flush();

      lcd.setCursor(0, 1);
      lcd.print("                ");
      lcd.setCursor(0, 1);
      lcd.print(temperature);
    }
    client.stop();                // tarminates the connection with the client
  }
  
}
