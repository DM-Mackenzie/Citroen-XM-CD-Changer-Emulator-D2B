# Citroen-XM-CD-Changer-Emulator-D2B

This is a project to create a CD changer "emulator" for a Citroen XM using the original Philips head-unit.
The Philips headunit can be coupled with an RC026 CD changer which is often mounted in the boot or under the front passenger seat.
As CD's are not as convenient as modern solutions like a smartphone with Bluetooth, an adapter would be fitting to allow for bluetooth playback over the original CD changer line.

Project goals are as follows:
- Create a bluetooth interface with A2DP and AVRCP. (Hands Free is optional, but not being worked on now)
- Incorporate a D2B transceiver; in this case, this will be the old but still available OKI MSM6307
- Write library for MSM6307
- Receiving commands on D2B bus
- Writing commands on D2B bus (name of song to headunit, which pushes it to the car's infoscreen through VAN)

For now, a rough draft of the following has been made by analyzing the MSM6307 datasheet
OKI_MSM6307.h
OKI_MSM6307.cpp
Included in this library is the build-up of a D2B frame. 

To-Do:
1. Analyzing used commands with a logic analyzer
2. Create database of known commands
3. Create prototype and test
