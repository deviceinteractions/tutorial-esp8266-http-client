/*  Surfing the internet with the ESP8266
    Written using the WiFIClientBasic Example Code
    20-Apr-18, Device Interactions

    This code lets the ESP8266 connect to any website using WiFi
    It shows you the html response received by the ESP8266 on the Serial Monitor

    1. Put your WiFi details at the #define WiFi_SSID and #define WiFi_PASS lines
    2. Put your desired website name in the #define SERVER_NAME line (for ideas - http://www.pointlesssites.com/)
    3. Open the Serial Monitor and set the baud rate to 9600 baud
    4. Upload this sketch to the ESP8266
    5. Look at the Serial Monitor
    6. You can copy the received html, paste it in a notepad window and save as *.html
    7. Then open it in a browser, and you will see the website ui there

    
    *The memory may overflow if the website html is large. Don't let that bother you!
    *Reset and try again :)

    Congrats, you just created a bot that connects to the internet!
*/
#include <Arduino.h>

#include <ESP8266WiFi.h>
#include <ESP8266WiFiMulti.h>

#include <ESP8266HTTPClient.h>

#define USE_SERIAL Serial
#define SERVER_NAME "http://www.hmpg.net/" // put the host name here. this is a sample
#define WIFI_SSID "YOUR-WiFi-NAME"
#define WIFI_PASS "YOUR-WiFi-PASSWORD"

ESP8266WiFiMulti WiFiMulti;

void setup() {

    USE_SERIAL.begin(9600);
   // USE_SERIAL.setDebugOutput(true);

    USE_SERIAL.println();
    USE_SERIAL.println();
    USE_SERIAL.println();
    USE_SERIAL.println("Clearing Serial buffer...");
    for(uint8_t t = 4; t > 0; t--) {
        USE_SERIAL.flush();
        delay(1000);
    }

    WiFiMulti.addAP(WIFI_SSID, WIFI_PASS);

}

void loop() {
    // wait for WiFi connection
    if((WiFiMulti.run() == WL_CONNECTED)) {

        HTTPClient http;

        USE_SERIAL.print("[HTTP] starting...\n");
        // configure traged server and url
        http.begin(SERVER_NAME); //HTTP

        USE_SERIAL.print("[HTTP] GET...\n");
        // start connection and send HTTP header
        int httpCode = http.GET();

        // httpCode will be negative on error
        if(httpCode > 0) {
            // HTTP header has been send and Server response header has been handled
            USE_SERIAL.printf("[HTTP] GET... code: %d\n", httpCode);

            // file found at server
            if(httpCode == HTTP_CODE_OK) {
                USE_SERIAL.print("[HTTP] Received HTML...\n");
                String payload = http.getString();
                USE_SERIAL.println(payload);
                USE_SERIAL.flush();
            }
        } else {
            USE_SERIAL.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
        }

        http.end();
    }

    delay(10000);
}

