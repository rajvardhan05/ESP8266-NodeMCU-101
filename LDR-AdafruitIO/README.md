Light Sensor Data Publishing to Adafruit IO using ESP8266
=========================================================

This project showcases an Internet of Things (IoT) setup using an ESP8266 microcontroller to capture data from a Light Dependent Resistor (LDR) and publish it to Adafruit IO. The setup allows remote monitoring of ambient light levels through an Adafruit IO dashboard.

Overview
--------

The code establishes a connection to a Wi-Fi network and Adafruit IO, facilitating the transmission of LDR readings at regular intervals. The captured data is then published to an Adafruit IO feed, enabling real-time tracking and analysis of light intensity variations.

Components
----------

-   **ESP8266 Wi-Fi Module:** Facilitates network connectivity and data transmission.
-   **Light Dependent Resistor (LDR):** Measures ambient light levels.
-   **Adafruit IO:** Cloud-based IoT platform used for data visualization and storage.

Usage
-----

### Requirements

-   Arduino IDE
-   ESP8266WiFi and Adafruit MQTT libraries

### Configuration

1.  Wi-Fi Setup: Enter your Wi-Fi credentials in the code by modifying `WLAN_SSID` and `WLAN_PASS` constants.
2.  Adafruit IO Setup: Set your Adafruit IO username and API key in `AIO_USERNAME` and `AIO_KEY`.
3.  LDR Pin Configuration: Define the pin to which your LDR is connected using `LDR_PIN`.

### Uploading Code

1.  Open the code in Arduino IDE.
2.  Configure the necessary parameters.
3.  Upload the code to your ESP8266.

### Monitoring

-   Open the Serial Monitor to observe LDR readings being transmitted to Adafruit IO.
-   Access your Adafruit IO dashboard to visualize and analyze the incoming light sensor data.

Notes
-----

-   Adjust the delay in the code (`delay(2000)`) to change the data transmission frequency.
-   Ensure a stable internet connection for uninterrupted data publishing.
-   Implement additional error handling or reconnection logic for robustness against connectivity issues.

Credits and Resources
---------------------

- [Adafruit IO Documentation](https://learn.adafruit.com/adafruit-io)

- [ESP8266WiFi Library](https://github.com/esp8266/Arduino/tree/master/libraries/ESP8266WiFi)

- [Adafruit MQTT Library](https://github.com/adafruit/Adafruit\_MQTT\_Library)

Feel free to contribute, modify, or use this code for your own IoT projects!