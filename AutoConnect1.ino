#include <ESP8266WiFi.h>          //https://github.com/esp8266/Arduino

//needed for library
#include <DNSServer.h>
#include <ESP8266WebServer.h>
#include <WiFiManager.h>         //https://github.com/tzapu/WiFiManager

#define BLYNK_PRINT Serial


#include <BlynkSimpleEsp8266.h>
char auth[] = "o5e4TpnkHmlBnRmgVHNLeLNELqLrdtJ_";

const int buttonPin = 5;
int buttonState = 0;

void setup() {
    // put your setup code here, to run once:
    Serial.begin(115200);

    pinMode(buttonPin, INPUT);
    buttonState = digitalRead(buttonPin);

    //WiFiManager
    //Local intialization. Once its business is done, there is no need to keep it around
    WiFiManager wifiManager;
    //reset saved settings
    
    if(buttonState == HIGH) { 
      //turn LED on
     wifiManager.resetSettings();
   }
   
    
    //set custom ip for portal
    //wifiManager.setAPConfig(IPAddress(10,0,1,1), IPAddress(10,0,1,1), IPAddress(255,255,255,0));

    //fetches ssid and pass from eeprom and tries to connect
    //if it does not connect it starts an access point with the specified name
    //here  "AutoConnectAP"
    //and goes into a blocking loop awaiting configuration
    wifiManager.autoConnect("AutoConnectAP");
    //or use this for auto generated name ESP + ChipID
    //wifiManager.autoConnect();

     Blynk.config(auth);

    
    //if you get here you have connected to the WiFi
    Serial.println("connected...yeey :)");
}

void loop() {
  
    // put your main code here, to run repeatedly:
     Blynk.run(); 
}
