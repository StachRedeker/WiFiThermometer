# WiFiThermometer
> WifiThermometer enables the user to transfer (sensor) data between two ESP8266 microcontrollers while utelizing an existing WiFi network.

My grandpa has a lovely little balcony. He would like to know the outside temperature without actually going outside. Sounds simple enough, but thick concrete walls make it impossible for any 433 MHz low power radio signal to penatrate. Simply buying an off-the-shelf wireless thermometer is hence not an option. Also, why bother placing a analog thermometer outside and walking to the window... if you can task you grandson and aspiring electrical engineer with developing an unnecessary complicated solution?

In true engineering fashion, I postponed this project for months. The idea from the start was to develop a system that transfers data using my grandpa's WiFi network. The WiFi signal is strong enough to be measurable on the balcony (gotta read that Facebook while sitting outside), so a solution that utelizes the existing WiFi network could be viable. 

This project idea may seem simple at first, but designing the final system was rather difficult. I had to overcome various struggles, ranging from faulty data cables (grrr) to finding the internal IP address of a router. Luckely, you can just steal my code and start playing with it right away. The end result is a system consising of two components: a *client* that measures the temperature using a DHT11 sensor and a *server* that receives the temperature reading and projects it on a 1602 LCD. Feel free to use this project as a template for other wireless transmission ideas: the only limitation is your imagination.

## Hardware setup

For my version of the system, you will need:
- two ESP8266 boards, of which at least one should be able to handle a 5V output
- DHT11 temperature sensor (a newer generation is also fine)
- 1602 LCD display with necessary potentiometer to adjust the brightness
- wires, breadboard, and suitable power supplies

### Client setup
The client is responsible for reading the sensor values and sending them to the server. You can use a 3.3V or a 5V board for this task.

Connect the DHT11 temperature sensor to the board. Connect power to power, ground to ground, and the signal pin to an arbitrary digital pin of the ESP8266.

### Server setup
The server is responsible for receiving the sensor values and displaying them on a LCD screen. Use a 5V board for the server, since the display requires 5V to work.

Connect the LCD screen:
- VSS to GND
- VDD to 5V
- V0 through potmeter to GND
- RS to D3
- RW to GND
- E to D2
- D4 to D4
- D5 to D5
- D6 to D6
- D7 to D7
- A to 5V (check if current limiting resistor is required)
- K to GND

That's all there is!

## Software setup



## Sources and acknowledgements 
