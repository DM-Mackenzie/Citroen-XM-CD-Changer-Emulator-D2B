**CD Changer Connector**
The headunit uses a CD changer cable with a connector as per the ISO 10487 standards, with a 10 pin connector. Although it's called a "C" connector, officially per the standard this is a "D" type connector, which is available for purchase. 
![image](https://github.com/user-attachments/assets/83dc67b8-32bc-4f44-a404-e6bba0df6b6e)
Rear of headunit, from the original service manual for the headunit

![image](https://github.com/user-attachments/assets/64ba6a51-76e4-4787-9cee-458197331b1c)
Excerpt from the service manual of the CD changer. 

As noted, the pinout is as follows:
1. Ground - D2B Ground Bus
3. D2B Bus 1 - Differential Pin 1
5. D2B Bus 2 - Differential Pin 2
6. NC
7. Permanent 14V - Might use this to keep MCU alive in low power state
8. Ground Power - Separate ground for 14V input.
9. Switched 14V - Switched from ignition. Might use this to awaken MCU.
10. Line in right - Right Audio Channel
11. Line in left - Left Audio Channel
12. Line in ground - Audio Ground
