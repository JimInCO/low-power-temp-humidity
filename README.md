# Low Power Temperature and Humidity Sensor
Has the schematics and code to create a battery power temperature and humidity sensor.
Based on the design from the [Home Circuits Blog](https://homecircuits.eu/blog/battery-powered-esp8266-iot-logger/).

## Schematic for Programming ATtiny13 with a Raspbery Pi
Here is the recommended pinout for programming the ATtiny13 with a Raspberry Pi

| Raspberry Pi Pin | ATtiny Pin | Comment         | Resistor |
|------------------|------------|-----------------|----------|
| 15               | 1          | GPIO22 to Reset | 1 kΩ     |
| 17               | 8          | 3.3 V           | None     |
| 19               | 5          | MOSI            | 1 kΩ     |
| 21               | 6          | MISO            | 1 kΩ     |
| 23               | 7          | SCLK            | 1 kΩ     |
| 25               | 4          | GND             | None     |

This figure shows the pinout of the ATtiny13
![ATtiny13 Pinout](images/ATtiny13.jpg)
