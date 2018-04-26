# An ESP8266 HTTP Client Tutorial with Arduino IDE

## An example code to connect an ESP8266 to the internet via WiFi and browse webpages

    This code lets the ESP8266 connect to any website using WiFi
    It shows you the html response received by the ESP8266 on the Serial Monitor

    1. Put your WiFi details in the #define WiFi_SSID and #define WiFi_PASS lines
    2. Put your desired website name in the #define SERVER_NAME line
    3. Open the Serial Monitor and set the baud rate to 9600 baud
    4. Upload this sketch to the ESP8266
    5. Look at the Serial Monitor
    6. You can copy the received html, paste it in a notepad window and save as *.html
    7. Then open it in a browser, and you will see the website ui there
    
* Please note that the ESP8266 may face a buffer overflow while Serial-printing the received HTML file if it is too large.
* For the purpose of this example, please try websites that are concise, like www.iamawesome.com
