#ifndef OKI_MSM6307_H
#define OKI_MSM6307_H

#include <Arduino.h>
#include <Wire.h>

// Fouten definities
enum MSM6307Error {
    MSM6307_OK,
    MSM6307_ERR_I2C,
    MSM6307_ERR_INVALID_COMMAND,
    MSM6307_ERR_TIMEOUT
};

class OKI_MSM6307 {
public:
    OKI_MSM6307();
    void begin();
    MSM6307Error writeRegister(uint8_t reg, uint8_t value);
    MSM6307Error readRegister(uint8_t reg, uint8_t &value);

    // Functies voor de specifieke registers
    MSM6307Error writeGlobalRegister(uint16_t address, bool hasMemory, bool enableTransmitter);
    MSM6307Error readLockAddressRegister(uint16_t &address);
    MSM6307Error writeMasterBuffer(uint8_t* data, size_t length);
    MSM6307Error readMasterBuffer(uint8_t* buffer, size_t length);
    MSM6307Error writeMasterCommandRegister(uint8_t value);
    MSM6307Error readMasterStatusRegister(uint8_t &value);
    MSM6307Error readSlaveReceiverBuffer(uint8_t* buffer, size_t length);
    MSM6307Error writeSlaveReceiverCommandRegister(uint8_t value);
    MSM6307Error readSlaveReceiverStatusRegister(uint8_t &value);
    MSM6307Error writeSlaveTransmitterBuffer(uint8_t* data, size_t length);
    MSM6307Error writeSlaveTransmitterCommandRegister(uint8_t value);
    MSM6307Error readSlaveTransmitterStatusRegister(uint8_t &value);
    MSM6307Error readInterruptRegister(uint8_t &value);
    MSM6307Error clearInterruptRegister(uint8_t value);
    MSM6307Error readSlaveStatusRegister(uint8_t &value);

    // Nieuwe functies voor specifieke commando's
    MSM6307Error processNextTrackCommand();
    MSM6307Error processPreviousTrackCommand();

private:
    const uint8_t _address = 0x20; // I2C address, dependent on A0, A1 & A2 grounding

    MSM6307Error processTrackCommand(uint8_t command);
};

#endif
