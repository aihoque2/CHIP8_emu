#include "CHIP8.h"


CHIP8::CHIP8(std::string filename){
    pc = 0x200;
    ReadRom(filename);

    /*
    read through ROM file and
    load it into memory()
    */

}

void CHIP8::ReadRom(std::string filename){
    /*
    read the ROM and load it into memory

    */
    filename_=filename.c_str();
    FILE* file = fopen(filename_, "r");

    // 2. Always check if the file opened successfully
    if (file == NULL) {
        perror("Error opening file");
        std::exit(EXIT_FAILURE);
    }

    int byte;
    while ((byte = fgetc(file)) != EOF) {
        
        // error check first then write to memory
        if (pc > 0xFFF){ // what if the ROM exceeds the size
            perror("Error in SetRom(): file size too big");
            std::exit(EXIT_FAILURE);
        }

        memory[pc] = static_cast<uint8_t>(byte);
        pc++;
        romSize++;
    }
    
    pc = 0x200;
}

void CHIP8::PrintRom(){

    // print rom from memory

    int address = 0x200;

    if (memory[address] == 0x200) {
        perror("PrintRom(): CHIP8 has not loaded memory\n");
        std::exit(EXIT_FAILURE);
    }

    while (address <= pc+romSize) {
        
        uint8_t byte = memory[address];
        // Print character safely (substitute non-printables with a dot)
        char display_char = (byte >= 32 && byte <= 126) ? static_cast<char>(byte) : '.';
        
        // Print Hexadecimal representation and character representation
        printf("Hex: 0x%02X | Char: %c\n", byte, display_char);
        address++;
    }
}

CHIP8::~CHIP8(){
}





