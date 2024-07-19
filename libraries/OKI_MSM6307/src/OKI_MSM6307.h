#ifndef OKI_MSM6307_H
#define OKI_MSM6307_H

#include <Arduino.h>
#include <Wire.h>

class OKI_MSM6307 {
public:
    OKI_MSM6307();
    void begin();
    bool writeRegister(uint8_t reg, uint8_t value);
    bool readRegister(uint8_t reg, uint8_t &value);

    // Functies voor de specifieke registers
    bool writeGlobalRegister(uint16_t address, bool hasMemory, bool enableTransmitter);
    bool readLockAddressRegister(uint16_t &address);
    bool writeMasterBuffer(uint8_t* data, size_t length);
    bool readMasterBuffer(uint8_t* buffer, size_t length);
    bool writeMasterCommandRegister(uint8_t value);
    bool readMasterStatusRegister(uint8_t &value);
    bool readSlaveReceiverBuffer(uint8_t* buffer, size_t length);
    bool writeSlaveReceiverCommandRegister(uint8_t value);
    bool readSlaveReceiverStatusRegister(uint8_t &value);
    bool writeSlaveTransmitterBuffer(uint8_t* data, size_t length);
    bool writeSlaveTransmitterCommandRegister(uint8_t value);
    bool readSlaveTransmitterStatusRegister(uint8_t &value);
    bool readInterruptRegister(uint8_t &value);
    bool clearInterruptRegister(uint8_t value);
    bool readSlaveStatusRegister(uint8_t &value);

    // Nieuwe functies voor specifieke commando's
    bool processNextTrackCommand();
    bool processPreviousTrackCommand();

private:
    const uint8_t _address = 0x20; // I2C address, dependent on A0, A1 & A2 grounding

    bool processTrackCommand(uint8_t command);
};

#endif
