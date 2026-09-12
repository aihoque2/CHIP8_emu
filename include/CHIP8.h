#ifndef CHIP8_H
#define CHIP8_H

#include <iostream>
#include <string>

class CHIP8{

public:
    CHIP8();
    void fetch();
    void decode();
    void execute();
    void ReadRom(std::string filename);

private:
    char** filename_;
    void** registers[16]{};
    uint8_t memory[4096]{};
    uint16_t index[]{};
    uint16_t pc{};
    uint16_t stack[16]{};
	uint8_t sp{};
	uint8_t delayTimer{};
    uint8_t keypad[16]{};
    uint32_t video[64 * 32]{};
    uint16_t opcode;
};

#endif