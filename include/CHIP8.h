#ifndef CHIP8_H
#define CHIP8_H

#include <iostream>
#include <string>
#include <cstdint>
#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>

#define SCALE 15

class CHIP8{

public:
    CHIP8();
    ~CHIP8();
    void fetch();
    void decode();
    void execute();
    void ReadRom(std::string filename);
    void PrintRom(); // call this after READROM;

private:
    char** filename_;
    void** registers[16]{}; // 16 registers (8-bit each)
    uint16_t index; // the index register (16 bits)
    uint8_t memory[4096]{};
    uint16_t pc{};
    uint16_t stack[16]{}; // 64-byte stack
	uint8_t sp{};
	uint8_t delayTimer{};
    uint8_t keypad[16]{};
    uint32_t video[SCALE * 64 * 32]{};
    uint16_t opcode;
    FILE* file; //file to open?
};

#endif