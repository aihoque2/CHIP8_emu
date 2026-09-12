/*
main.cpp

this is what is used to run the emulator.
*/
#include <iostream>

int main(int argc, char** argv){
    if (argc != 4 ){
            stderr << "Usage: " << argv[0] << " <Scale> <Delay> <ROM>\n";
    		std::exit(EXIT_FAILURE);
    }

	int videoScale = std::stoi(argv[1]);
	int cycleDelay = std::stoi(argv[2]);
	char const* romFilename = argv[3];

    CHIP8 chip8;

    return 0;
}