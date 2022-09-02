# WiFiThermometer
> WifiThermometer enables the user to transfer (sensor) data between two ESP8266 microcontrollers while utelizing an existing WiFi network.

My grandpa has a lovely little balcony. He would like to know the outside temperature without actually going outside. Sounds simple enough, but thick concrete walls make it impossible for any 433 MHz low power radio signal to penatrate. Simply buying an off-the-shelf wireless thermometer is hence not an option. Also, why bother placing a analog thermometer outside and walking to the window... if you can task you grandson and aspiring electrical engineer with developing an unnecessary complicated solution?

In true engineering fashion, I postponed this project for months. The idea from the start was to develop a system that transfers data using my grandpa's WiFi network. The WiFi signal is strong enough to be measurable on the balcony (gotta read that Facebook while sitting outside), so a solution that utelizes the existing WiFi network could be viable. 

This project idea may seem simple at first, but designing the final system was rather difficult. I had to overcome various struggles, ranging from faulty data cables (grrr) to finding the internal IP address of a router. Luckely, you can just steal my code and start playing with it right away. The end result is a system consising of two components: a *client* that measures the temperature using a DHT11 sensor and a *server* that receives the temperature reading and projects it on a 1602 LCD. Feel free to use this project as a template for other wireless transmission ideas: the only limitation is your imagination.

## Hardware setup

For my version of the system, you will need:
- Two ESP8266 boards, of which at least one should be able to handle a 5V output



```sh
npm install my-crazy-module --save
```

Windows:

```sh
edit autoexec.bat
```

## Software setup

A few motivating and useful examples of how your product can be used. Spice this up with code blocks and potentially more screenshots.

_For more examples and usage, please refer to the [Wiki][wiki]._

## Sources and acknowledgements 
