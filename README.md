# I-made-my-own-USB-DOCTOR-
This is compatible to any fast charger and you can monitor 2 parameters (current and voltage) in real time.
![THUMB](https://user-images.githubusercontent.com/97245507/211195455-b5431c2a-7dda-48c9-b27d-31be7ac75536.JPG)

A lot of power meters available in market which delicately made to work with 5volt charger power. The maximum ratings of my commercial one is 7v at 2amps. Now I want to use this USB charger doctor with my fast charger but it is not compatible at all. That’s why designing of this DIY charger came into my mind. My fast charging adaptor goes upto a rating of 80watts. A voltage divider network is used to measure the voltage upto 20volts with a current rating of 5ampere. I want to display the real time readings of this USB doctor on a small display and I choose atmega328p as a microcontroller and SSD 1306 128x32 OLED display of it.
![mini_IMG_3744](https://user-images.githubusercontent.com/97245507/211195489-746cb4d0-609b-45a6-8bc1-1a731efd46fe.JPG)
https://jlcpcb.com/see
Voltage readings are direct measurable with 10-bit internal ADC of the microcontroller which gives a resolution of 15mV and I used dedicated ACS712 for the current measurements. Which is based on hall effect and using this current readings can be easily converted into respected voltages and then any variation in current produce variation in voltage (For 5v ACS take 2.5v as a reference). To know more about ACS712 and it’s different variants check the data sheet from here.
![mini_IMG_3745](https://user-images.githubusercontent.com/97245507/211195494-4a088d4b-3021-4343-bbf6-9529fd1f80ee.JPG)

I prefer to make a PCB for this project because you can directly plug this into charger socket. Variation due to wires and tracks will be very less. I am using JLCPCB for the PCB prototypes, JLCPCB is China based PCB manufacturing company deals in a lot of PCB products including SMT assembly, precision PCB, stencil making and 3-D printing.
https://jlcpcb.com/see

Components Required:
![mini_IMG_3742](https://user-images.githubusercontent.com/97245507/211195505-1cb22d0b-58c7-481f-9aff-fa73875f13fb.JPG)

Arduino nano or Atmega328p
ACS712 5A version
SSD1306 OLED 128x32 display
10k, 4.7k resistors
100nf and 10nf ceramic capacitors
Ams1117 5v
USB Type A connectors
16MHz crystal oscillator
Custom PCB from JLCPCB

Circuit diagram:
![mini_IMG_3776](https://user-images.githubusercontent.com/97245507/211195522-c3cee618-7a01-4fce-9cfa-092b221f0bcb.JPG)

I made this circuit using EasyEDA because it is very compatible to JLCPCB. I used a 5v linear step down convertor to power the microcontroller and other peripherals. rather connecting pin headers of Arduino Uno I designed a circuit which has same properties using the microcontroller IC and 16MHz crystal.
<img width="433" alt="ice_screenshot_20230108-170813" src="https://user-images.githubusercontent.com/97245507/211195542-e62b6a6d-3bab-4c6a-a9d3-b176b08b165b.png">

All the connection details are given here in the schematics. Keep one thing in mind, If you want to use this USB charging doctor with fast-charger then datelines of USB need to be connect to each other. Phone gets an interrupt using these data-lines when a fast charger is detected.

PCB and design:
![mini_IMG_3778](https://user-images.githubusercontent.com/97245507/211195567-83dba02f-24a0-4a94-96b9-91e4ec2a0202.JPG)
https://jlcpcb.com/see
I made a really small PCB having microcontroller on one side and on board pin headers for the small screen. One male and female USB connector, to give power to the system and other one for the power output. I will recommend to use USB 3.0 socket because they are more durable and has very good connection approach.
<img width="987" alt="usb doctor pcb" src="https://user-images.githubusercontent.com/97245507/211195584-f0604c8e-75c1-42ee-bf28-bc39c6ab63d8.png">

You can download the Gerber files from here, my PCB is made using FR4 material and HASL finish which  costs me around $2 for the 5 piece. You can also use SMT assembly service offered by JLCPCB at a very low cost starting from just $8. Sign-up now to JLCPCB and get free coupons of worth $54 as new user.
https://jlcpcb.com/see

Programming the MCU:
https://www.youtube.com/watch?v=mI4VbfxbwRo&t=2s
Either you can use a preprogram MCU from a Arduino board or you can use the SPI headers. The connection details are given here. You can watch thus video which has proper instructions to burn the bootloader and to program an external MCU using Arduino board.

Testing and measurements:
![mini_IMG_3756](https://user-images.githubusercontent.com/97245507/211195600-b1ce47d0-9e5d-4da7-815e-a6c73186c5db.JPG)

This is a plug and play device, the real time readings can be seen on the screen once powered by any source. This USB device is working very well with fast charger. I have shared the updated schematics and Gerber files with you so no need to connect external data wires. Try JLCPCB for faster and Low cost PCB and we will see you next time with an another tutorial
https://jlcpcb.com/see
