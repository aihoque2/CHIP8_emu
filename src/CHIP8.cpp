#include "CHIP8.h"


CHIP8::CHIP8(std::string filename){
    pc = 0x200;
    SetRom(filename);

    /*
    read through ROM file and
    load it into memory()
    */

}

void CHIP8::SetRom(std::string filename){
    /*
    read and stream the ROM

    */

    file = fopen(filename.c_str(), "r");

    // 2. Always check if the file opened successfully
    if (file == NULL) {
        perror("Error opening file");
        std::exit(EXIT_FAILURE);
    }


}

void CHIP8::PrintRom(){
    if (file == NULL) {
        perror("Function PrintRom() has no filename\n");
        std::exit(EXIT_FAILURE);
    }

    int byte;
    while ((byte = fgetc(file)) != EOF) {
        
        // Print character safely (substitute non-printables with a dot)
        char display_char = (byte >= 32 && byte <= 126) ? static_cast<char>(byte) : '.';
        
        // Print Hexadecimal representation and character representation
        printf("Hex: 0x%02X | Char: %c\n", byte, display_char);

    }
}

CHIP8::~CHIP8(){
    // Close the file handle to free resources
    fclose(file);
}





