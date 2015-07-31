#ifndef __CODEC_H__
#define __CODEC_H__

using namespace std;

unsigned short convert_16_bit_to_14_bit_int( signed short  _16_bit );
signed short convert_14_bit_to_16_bit_int( unsigned short  _14_bit );
string encode(unsigned short in);
unsigned short decode(string hex_string);

#endif
