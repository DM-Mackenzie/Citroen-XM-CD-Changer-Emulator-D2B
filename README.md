# Philips CD-Changer Emulator D2B

This is a project to create a CD changer "emulator" for a Citroen XM using the original Philips head-unit.
The Philips headunit can be coupled with an RC026 CD changer which is often mounted in the boot or under the front passenger seat.
As CD's are not as convenient as modern solutions like a smartphone with Bluetooth, an adapter would be fitting to allow for bluetooth playback over the original CD changer line.
Philips headunits were commonly found in the 90's in several different types of cars. Although CD changer emulators have been designed for a lot of different headunits used in the past 30 years, I was unable to find any information for one that would suit this headunit; I suspect it has to do with the D2B communication protocol, of which I could not find a lot of information regarding DIY projects.

The CD Changer communicates with the headunit through D2B (Domestic Digital Bus). On this bus, CD changer presence and address are determined, and various code is sent across for remote control. This includes:
- Changing current track, next or previous
- Changing the CD, next or previous
- CD changer sending data which CD bay is currently playing (CD 1 - 6)

Project goals are as follows:
- Create a bluetooth interface with A2DP and AVRCP. (Hands Free is optional, but not being worked on now)
- Incorporate a D2B transceiver; in this case, this will be the old but still available OKI MSM6307
- Write library for MSM6307
- Receiving commands on D2B bus
- Writing commands on D2B bus (name of song to headunit, which pushes it to the car's infoscreen through VAN)
- Have a webinterface to see current bluetooth device and track info, and change various options, such as language, whether or not to send track info.
- Unit must be plug and play. No additional wiring is needed as it can use the original CD changer connector, which provides us with everything we need.

For now, a rough draft of the following has been made by analyzing the MSM6307 datasheet
OKI_MSM6307.h
OKI_MSM6307.cpp
Included in this library is the build-up of a D2B frame. 

To-Do:
1. Analyzing used commands with a logic analyzer
2. Create database of known commands
3. Create prototype and test

Planned hardware:
- ESP32 based MCU board
- OKI MSM6307 IC
- Fully automotive compliant power supply to avoid as much noise as possible
- Very short twisted pair lead to the radio connector, using a plug and play ISO 10487 type D connector

For this a custom PCB will be created. 
