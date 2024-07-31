# ESP32 Audio Sink

The ESP-IDF libraries allow for the use of A2DP and AVRCP. This part of the project will be used to test several items relating to the audio- and remote control part of the project.
As it stands now, the following is working:
1. Starting a bluetooth audio sink
2. Sending remote control messages to the connected device through AVRCP
3. Receiving metadata

> [!NOTE]
> Although the Arduino framework has been used to create succesful A2DP sinks, I ran into several issues while experimenting with this framework, most notably Watch Dog Timer issues. This could occur for a multitude of reasons, but after transferring the project to the ESP-IDF framework the errors did not occur anymore. I suspect it had to do with the metadata callback causing a high cpu load, or the Arduino Loop; the loop works very well for simple projects and code, but in more complex projects this can cause issues. Although the learning curve is more steep, the ESP-IDF framework with FreeRTOS will be used, as the ESP32 must also handle D2B communication (and ideally also a webpage that is desired) at the same time.

Currently work needs to be done on the following items:
1. Setting pre-defined and user changable pincode for bluetooth connection for security
2. Setting Bluetooth Class of Device to let connected devices know which type of device it is. The adapter will be advertised as a car stereo
3. Create variables for user defined settings (pincode, name) so the end-user can change these settings into their own desired names and codes
