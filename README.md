# Wifi Driven Remote Rubber Ducky
#### _Utilizes Open Source Hardware (Arduino, Teensy)_ 

<img src="https://cdn.icon-icons.com/icons2/2699/PNG/512/arduino_logo_icon_168572.png" width="200" height="100" />

This is an implementation of a bad USB concept, with the addition of remote execution supported by open source hardware. In this case a Wi-Fi module for the Arduino platform.

### Requirements✨

- Arudino UNO or Leonardio or any compatible substitute.
- The Wi-Fi module (Known as the Wi-Fi shield)

### Objective✨
> Proof of concept for a hardware based attack, built as part of a uni project. While demonstrating other vibale use cases for such hardware. As:
>
> > <font size="2"> 💡 Remote Console Cable. Driven by a Wi-Fi network.</font> 
> 
> > <font size="2"> 💡 Remote Packet generator by utilizing an ethernet interface combined with the Wi-Fi module.</font> 

### Usage ✨
This functions by plugging in the arduino to a target machine whereby the following occurs:
- The USB hardware connects to given Wi-FI network (Statically defined).
- Allows the user to send key presses as a payload via the python code.
```sh
Example > python payload_transmitter.py Settings.yaml attack_1

Sample Attacks >>
  - attack_1 = Wifi Password Dump and Send via Email
  - attack_2 = Poison DNS
  - attack_3 = Remote Shell
```


### Additional Explanation ✨
The payload encodes the key-presses in a string delimited by "," for key-presses and "." from delay between strokes. 

This allows for any combination to be sent to the bad USB for delivery regardless of the platform. Additionally, this uses the standard operating systems keyboard driver so compatibility is wide.

#### To-Do:
- Addition of Tests.

- Optimize the bytes used on the server side.