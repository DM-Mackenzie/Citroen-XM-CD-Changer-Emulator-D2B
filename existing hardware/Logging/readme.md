# Analyzing using logic analyzer
To log the existing lines, the following is used:
1. Logic analyzer (Chinesium brand)
2. Pulseview as software to use with it (if this doesn't work reliably, might use Saleae)

## Analyzing the D2B line

We have a theoretical confirmation of the protocol used in this project (D2B) between the headunit and the CD-changer, and how this functions. Prior to testing this out, a D2B library was created based on the datasheet for the MSM6307 IC. However, we are missing some variables required for operation:
1. Master address (headunit)
2. Slave address (CD changer)

As the CD changer works on a multitude of different Philips headunits, I believe the headunit has an address that has been allocated within the D2B protocol space as "headunit", so it will work on different models. This can also be true for the CD changer. The IEC standard does not provide any insights into this, apart from a generic class of devices (audio/video). 

Furthermore, as D2B is only a manner of communication, we need to scan for the following:
1. Messages indicating presence on the bus
2. "stay alive" commands, or repeating commands to let the headunit know the CD changer is present
3. Commands regarding playback: pause, next, previous, next CD, previous CD and other
4. Other misc. commands that can be started on either the steering wheel controls or headunit itself
5. Commands or messages that contain other information, such as playtime, CD number. In the best-case, the CD-number that is indicated on the headunit and VAN screen are not pre-programmed but are made of D2B messages containing commands. This would allow us to send custom messages (Metadata from AVRCP).

The test-setup is as follows:
1. Steering wheel controls, which are mimicked by resistors on a breadboard with buttons
2. Headunit itself
3. Loose infoscreen with only VAN and power connected
4. 12V PSU from an old computer, using a breakout board to provide power
5. CD changer

The dataline has a frequency of 6MHz, which should work with our cheap analyzer. 

## Analyzing the line-input
Currently the specifications for the dataline are unknown. Althought the headunit can probably handle a multitude of different line properties, ideally I'd match all properties as close as possible. I do not have an oscilloscope yet
