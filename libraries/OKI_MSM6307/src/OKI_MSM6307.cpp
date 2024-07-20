#include "OKI_MSM6307.h"

OKI_MSM6307::OKI_MSM6307() {}

void OKI_MSM6307::begin() {
    Wire.begin();
}

MSM6307Error OKI_MSM6307::writeRegister(uint8_t reg, uint8_t value) {
    Wire.beginTransmission(_address);
    Wire.write(reg);
    Wire.write(value);
    if (Wire.endTransmission() != 0) {
        return MSM6307_ERR_I2C;
    }
    return MSM6307_OK;
}

MSM6307Error OKI_MSM6307::readRegister(uint8_t reg, uint8_t &value) {
    Wire.beginTransmission(_address);
    Wire.write(reg);
    if (Wire.endTransmission() != 0) {
        return MSM6307_ERR_I2C;
    }

    Wire.requestFrom(_address, (uint8_t)1);
    if (Wire.available()) {
        value = Wire.read();
        return MSM6307_OK;
    }
    return MSM6307_ERR_TIMEOUT;
}

MSM6307Error OKI_MSM6307::writeGlobalRegister(uint16_t address, bool hasMemory, bool enableTransmitter) {
    Wire.beginTransmission(_address);
    Wire.write(0x00);
    Wire.write((address >> 4) & 0xFF); // High nibble
    uint8_t lowByte = (address & 0x0F) << 4;
    if (hasMemory) lowByte |= 0x08;
    if (enableTransmitter) lowByte |= 0x02;
    Wire.write(lowByte);
    if (Wire.endTransmission() != 0) {
        return MSM6307_ERR_I2C;
    }
    return MSM6307_OK;
}

MSM6307Error OKI_MSM6307::readLockAddressRegister(uint16_t &address) {
    uint8_t high, low;
    MSM6307Error err = readRegister(0x01, high);
    if (err != MSM6307_OK) return err;
    err = readRegister(0x01, low);
    if (err != MSM6307_OK) return err;
    address = (high << 8) | low;
    return MSM6307_OK;
}

MSM6307Error OKI_MSM6307::writeMasterBuffer(uint8_t* data, size_t length) {
    Wire.beginTransmission(_address);
    Wire.write(0x02);
    for (size_t i = 0; i < length; i++) {
        Wire.write(data[i]);
    }
    if (Wire.endTransmission() != 0) {
        return MSM6307_ERR_I2C;
    }
    return MSM6307_OK;
}

MSM6307Error OKI_MSM6307::readMasterBuffer(uint8_t* buffer, size_t length) {
    Wire.beginTransmission(_address);
    Wire.write(0x03);
    if (Wire.endTransmission() != 0) {
        return MSM6307_ERR_I2C;
    }

    Wire.requestFrom(_address, length);
    for (size_t i = 0; i < length; i++) {
        if (Wire.available()) {
            buffer[i] = Wire.read();
        } else {
            return MSM6307_ERR_TIMEOUT;
        }
    }
    return MSM6307_OK;
}

MSM6307Error OKI_MSM6307::writeMasterCommandRegister(uint8_t value) {
    return writeRegister(0x0A, value);
}

MSM6307Error OKI_MSM6307::readMasterStatusRegister(uint8_t &value) {
    return readRegister(0x0B, value);
}

MSM6307Error OKI_MSM6307::readSlaveReceiverBuffer(uint8_t* buffer, size_t length) {
    Wire.beginTransmission(_address);
    Wire.write(0x05);
    if (Wire.endTransmission() != 0) {
        return MSM6307_ERR_I2C;
    }

    Wire.requestFrom(_address, length);
    for (size_t i = 0; i < length; i++) {
        if (Wire.available()) {
            buffer[i] = Wire.read();
        } else {
            return MSM6307_ERR_TIMEOUT;
        }
    }
    return MSM6307_OK;
}

MSM6307Error OKI_MSM6307::writeSlaveReceiverCommandRegister(uint8_t value) {
    return writeRegister(0x0C, value);
}

MSM6307Error OKI_MSM6307::readSlaveReceiverStatusRegister(uint8_t &value) {
    return readRegister(0x0D, value);
}

MSM6307Error OKI_MSM6307::writeSlaveTransmitterBuffer(uint8_t* data, size_t length) {
    Wire.beginTransmission(_address);
    Wire.write(0x06);
    for (size_t i = 0; i < length; i++) {
        Wire.write(data[i]);
    }
    if (Wire.endTransmission() != 0) {
        return MSM6307_ERR_I2C;
    }
    return MSM6307_OK;
}

MSM6307Error OKI_MSM6307::writeSlaveTransmitterCommandRegister(uint8_t value) {
    return writeRegister(0x0E, value);
}

MSM6307Error OKI_MSM6307::readSlaveTransmitterStatusRegister(uint8_t &value) {
    return readRegister(0x0F, value);
}

MSM6307Error OKI_MSM6307::readInterruptRegister(uint8_t &value) {
    return readRegister(0x07, value);
}

MSM6307Error OKI_MSM6307::clearInterruptRegister(uint8_t value) {
    return writeRegister(0x08, value);
}

MSM6307Error OKI_MSM6307::readSlaveStatusRegister(uint8_t &value) {
    return readRegister(0x09, value);
}

/**
 * Process the track command based on the given command value.
 * @param command The command value to process.
 * @return True if the command was processed successfully, false otherwise.
 */
MSM6307Error OKI_MSM6307::processTrackCommand(uint8_t command) {
    uint8_t buffer[1];
    MSM6307Error err = readSlaveReceiverBuffer(buffer, 1);
    if (err != MSM6307_OK) return err;

    if (buffer[0] == command) {
        // Voer hier de specifieke actie uit, bijvoorbeeld:
        // - Verhoog of verlaag het tracknummer
        // - Update de status van de headunit
        return MSM6307_OK;
    }
    return MSM6307_ERR_INVALID_COMMAND;
}

/**
 * Process the "Next Track" command.
 * @return True if the command was processed successfully, false otherwise.
 */
MSM6307Error OKI_MSM6307::processNextTrackCommand() {
    return processTrackCommand(0x73); // Increment command
}

/**
 * Process the "Previous Track" command.
 * @return True if the command was processed successfully, false otherwise.
 */
MSM6307Error OKI_MSM6307::processPreviousTrackCommand() {
    return processTrackCommand(0x63); // Decrement command
}
