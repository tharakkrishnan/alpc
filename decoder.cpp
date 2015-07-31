#include <iostream>
#include <sstream>
#include <stdio.h>

#include "codec.h"



void usage(){
	
	cout << "Usage: bit14decode requires a single mandatory argument."<<     endl
		 << "Invocation: bit14decode <hexadecimal string between 0000 and 7F7F>" << endl;
		exit();
}

int main(int argc, char *argv[]) {
		
		signed short user_in, _16_bit;
		string hex_string;
		unsigned short _14_bit;
		
		if(argc != 2)
			usage();
			
		hex_string = string(argv[1]);

		
		std::stringstream ss;
		ss << std::hex << hex_string;
		ss >> user_in;
		
		if (user_in > 0x7F7F)
			usage(); 

			
		
		cout << "14 bit signed encoded into hex string:  "<< hex_string << endl;
		
		_14_bit = decode(hex_string);
		
		cout << "hex string decoded back into 14 bit:    "<< _14_bit << endl;

		
		_16_bit = convert_14_bit_to_16_bit_int(_14_bit);
		
		cout  << "output in 16 bit signed decimal:       "<< std::dec <<_16_bit << endl;

	
}
