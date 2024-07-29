**Line Input Channel**

We want to match the existing line channel properties to ensure performance will not be compromised. the following needs to be known and applied:
1. Impedance of existing CD changer DAC (Ohm):   _Unknown, needs to be checked_
2. Sampling rate (KHz):  _Unknown, needs to be checked. Probably 44100 or 48000 Hz_
3. Peak to peak voltage:  From buffer, 4.4V peak to peak
4. Bit input data:  _Unknown, needs to be checked; either 16 or 20 bit_

Various original specs (from CD changer service manual):

Original DAC: PCM1710U, with NJM2100 buffer
- Supports 16 or 20 bits input data
- Typical max output voltage swing: +-2.2V, (4.4V peak to peak)

Of course, it may be possible to send a higher quality signal with different properties (for example, 32bit audio with 96 kHz signal with higher peak to peak voltage) but that is not the aim of this project.
By matching the original specifications the audio quality will be of acceptable quality as compared to the original, as this project uses a modern DAC with much better audio quality and properties. The head-unit amplifier will be the bottleneck in any case.
