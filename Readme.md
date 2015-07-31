#Part 1: Encoding and Decoding Values

This should take an hour or so.

For this task, you need to write a small program including a pair of functions that can

1. convert an integer into a special text encoding and then

2. convert the encoded value back into the original integer.

Assuming that your solution works correctly and cleanly enough to move forward in this process, these functions will need

to be used in your part 2 submission.

The Encoding Function

This function needs to accept a signed integer in the 14-bit range [-8192..+8191] and return a 4 character string.

The encoding process is as follows:

1. Add 8192 to the raw value, so its range is translated to [0..16383]

2. Pack that value into two bytes such that the most significant bit of each is cleared 

Unencoded intermediate value (as a 16-bit integer):

 00HHHHHH HLLLLLLL

 

Encoded value:

 0HHHHHHH 0LLLLLLL

 

3. Format the two bytes as a single 4-character hexadecimal string and return it.

Sample values:

Unencoded (decimal) 	Intermediate (decimal) 	Intermediate (hex) 	Encoded (hex)

0 			8192 			2000 			4000

-8192 			0 			0000 			0000

8191 			16383 			3fff 			7F7F

2048 			10240 			2800 			5000

-4096 			4096 			1000 			2000

#The Decoding Function

Your decoding function should accept two bytes on input, both in the range [0x00..0x7F] and recombine them to return the

corresponding integer between [-8192..+8191]

Hi byte Lo byte Value

40 	00 	0

00 	00 	-8192

7F 	7F 	8191

50 	00 	2048

0A 	05 	-6907

55 	00 	2688

Your Task

You should supply source code (and whatever additional collateral files may be necessary or useful for us to understand,

validate, and test your submission) for a working program that can accept text input in either decimal integer or

hexadecimal format and convert between the two formats.

This program can be a command line application that reads from stdin or a file and writes to stdout or a file, or could be a

web page or mobile/desktop app that uses a text edit box to accept input values by typing or pasting (or loading a file) and

a button to convert that input into the desired output format so you can encode/decode sample data as described below.
