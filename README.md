# virtuaaliluonto-lumivahti

# Ideas
- snow depth
- temperature
- no need for constant data - measurements once per hour
- battery and possible solar panel
- weather proof
- data published online


# Execution
- Arduino or ESP8266 based
- sensors: ultrasound sensor to measure distance, thermistor for temperature
- weatherproofing: waterproof coating? a case for arduino. Ultrasonic sensor must be exposed?
- Arduino gathers data and sends it to server once per hour. MQTT or HTTP API
- Webpage on a server that displays results

# Testing
- mainly outdoors. More data needed for the distance sensor.

# Links
http://terokarvinen.com/2017/aikataulu-monialaprojekti-infra-pro4tn001-5-kevat-2018-10-op
https://raspluonto.wordpress.com/
https://www.geekstips.com/arduino-snow-depth-remote-sensing-with-ultrasonic-sensor/
http://www.instructables.com/id/Solar-Powered-WiFi-Weather-Station/
