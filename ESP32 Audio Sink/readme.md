# ESP32 Audio Sink

The ESP-IDF libraries allow for the use of A2DP and AVRCP. This part of the project will be used to test several items relating to the audio- and remote control part of the project.
As it stands now, the following is working:
1. Starting a bluetooth audio sink
2. Sending remote control messages to the connected device through AVRCP
3. Receiving metadata

Currently work needs to be done on the following items:
1. Setting pre-defined and user changable pincode for bluetooth connection for security
2. Setting Bluetooth Class of Device to let connected devices know which type of device it is. The adapter will be advertised as a car stereo.
3. Create variables for user defined settings (pincode, name)
