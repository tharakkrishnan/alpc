#include <iostream>
#include <sstream>
#include <stdio.h>
#include "codec.h"

using namespace std;


void usage(){
	
	cout << "Usage: bit14encode requires a single mandatory argument."<<     endl
		 << "Invocation: bit14encode <decimal integer between -8192 and 8191>" << endl;
		exit();
}

int main(int argc, char *argv[]) {
		
		signed short user_in;
		string hex_string;
		unsigned short _14_bit;
		
		if(argc != 2)
			usage();
		
		std::stringstream ss;
		ss << std::dec << string(argv[1]);
		ss >> user_in;
		
		if (user_in < -8192 || user_in > 8192)
			usage(); 

				
		_14_bit = convert_16_bit_to_14_bit_int(user_in);
		cout  << "user input 16 bit signed:	          " <<  std::dec << user_in<< endl;
		cout  << "input in 14 bit signed:                " <<  std::hex << _14_bit << endl;
		
		hex_string = encode(_14_bit);
		
		cout << "14 bit signed encoded into hex string:  "<< hex_string << endl;
		
return 0;
	
}
