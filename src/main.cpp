/*
main.cpp

this is what is used to run the emulator.
*/
#include <iostream>
#include "CHIP8.h"

// to run just do this for now: ./main 1 1 ../pong_1_player.ch8

int main(int argc, char** argv){
    if (argc != 4 ){
            std::cout << "Usage: " << argv[0] << " <Scale> <Delay> <ROM>\n";
    		std::exit(EXIT_FAILURE);
    }

	int videoScale = std::stoi(argv[1]);
	int cycleDelay = std::stoi(argv[2]);
	char const* romFilename = argv[3];

    CHIP8 chip8("../pong_1_player.ch8");
    chip8.PrintRom();

    return 0;
}