**Line Input Channel**

We want to match the existing line channel properties to ensure performance will not be compromised. the following needs to be known and applied:
1. Impedance of existing CD changer DAC (Ohm):   _Unknown, needs to be checked_
2. Sampling rate (KHz):  _Unknown, needs to be checked. Probably 44100 or 48000 Hz_
3. Peak to peak voltage:  From buffer, 4.4V peak to peak
4. Bit input data:  _Unknown, needs to be checked; either 16 or 20 bit_

Various original specs (from CD changer datasheet):

Original DAC: PCM1710U, with NJM2100 buffer
- Supports 16 or 20 bits input data
- Typical max output voltage swing: +-2.2V, (4.4V peak to peak)

Distortion _< 0.01% (at 1kHz)

Data - Track mute _> 93dB (A-weighted)

DAC Resolution: 1 bit per channel

Crosstalk L<>R _< -75dB

S/N Ratio: 96dB

Output voltage: 700mV

