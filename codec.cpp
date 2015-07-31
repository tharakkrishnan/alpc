#include <iostream>
#include <sstream>
#include <stdio.h>

#include "codec.h"



unsigned short convert_16_bit_to_14_bit_int( signed short  _16_bit ){
	
	unsigned short _14_bit = (_16_bit & 0x1FFF);
	
	_16_bit&0x2000 ? _14_bit |= 0x2000 : _14_bit;

	return _14_bit;
}

signed short convert_14_bit_to_16_bit_int( unsigned short  _14_bit ){
	
	unsigned short _16_bit = _14_bit & 0x1FFF;
	
	_14_bit&0x2000 ? _16_bit |= 0xE000 : _16_bit;

	return _16_bit;
}

string encode(unsigned short in){
	unsigned short intermediate, final;
	string hex_string;

	(in & 0x2000) ? intermediate = ((in & 0x3FFF) - 0x2000) : intermediate = ((in & 0x3FFF) + 0x2000);
	cout << "intermediate: " << intermediate << endl;

	final = ((intermediate << 1) & 0x7F00) | (intermediate & 0x007F);
	
	cout << "final: " << final << endl;
	
	std::stringstream ss;
	    ss << std::hex << final;
	    ss >> hex_string;
	
	return hex_string;
}


unsigned short decode(string hex_string){	
	
	unsigned short intermediate, final;   
	std::stringstream ss;
	ss << std::hex << hex_string;
	ss >> intermediate;
	cout << "intermediate: " << intermediate << endl;

	final = ((intermediate >> 1) & 0x3F80) | (intermediate & 0x7F);
	
	final = (final - 0x2000) & 0x3FFF;
	cout << "final: " << final << endl;

	
	return final;
	
}


#if 0

void usage(){
	
	cout << "Usage: bit14codec requires a single mandatory argument."<<     endl
		 << "Invocation: codec <decimal integer between -8192 and 8191>" << endl;
		exit();
}


int main(int argc, char *argv[]) {
		
		signed short user_in, _16_bit;
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
		
		_14_bit = decode(hex_string);
		
		cout << "hex string decoded back into 14 bit:    "<< _14_bit << endl;

		
		_16_bit = convert_14_bit_to_16_bit_int(_14_bit);
		
		cout  << "output in 16 bit signed decimal:       "<< std::dec <<_16_bit << endl;

	
}

#endif
