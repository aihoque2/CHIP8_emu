#include "CHIP8.h"
#include <stdio.h>
#include <stdlib.h>

void CHIP8::ReadRom(std::string filename){
    /*
    read and stream the ROM

    */

    file = fopen(filename);

    // 2. Always check if the file opened successfully
    if (file == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }
}

void CHIP8::PrintRom(){
    if (file == NULL) {
        stderr << "Function PrintRom() has no filename  <Scale> <Delay> <ROM>\n";
        return EXIT_FAILURE;
    }


    unint8_t byte;
    while ((byte = fgetc(file)) != EOF) {
        
        // Print character safely (substitute non-printables with a dot)
        char display_char = (byte >= 32 && byte <= 126) ? (char)byte : '.';
        
        // Print Hexadecimal representation and character representation
        printf("Hex: 0x%02X | Char: %c\n", byte, display_char);

    }
}

CHIP8::~CHIP8(){
    // Close the file handle to free resources
    fclose(file);
}





