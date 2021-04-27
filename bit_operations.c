#include <stdio.h>


// check if bit in given position is set or reset
int isset(unsigned char bitSet, int bitPosition) {
	/*
	 * bitSet: any integer between 0 - 255, inclusive
	 * bitPosition: the position of the bit to check, 0 - 7
	 * return: 1 if bit is on, 0 if bit is off
	 */

	unsigned char bitMask = 0x01;
	bitMask = bitMask << bitPosition;

	if (bitSet & bitMask) {
		return 1;
	}
	
	return 0;
}

// set bit in target position
void addbit(unsigned char *bitSet, int bitPosition) {
	/*
	 * *bitSet: address of an 8-bit unsigned integer, 0 - 255
	 * bitPosition: position of the bit to set, 0 - 7
	 */	

	unsigned char bitMask = 0x01;
	bitMask = bitMask << bitPosition;

	if (!(*bitSet & bitMask)) {
		*bitSet = *bitSet | bitMask;
	}
}

// reset bit in target position
void delbit(unsigned char *bitSet, int bitPosition) {
	/*
	 * *bitSet: address of an 8-bit unsigned integer, 0 - 255
	 * bitPosition: position of the bit to reset, 0 - 7
	 */

	unsigned char bitMask = 0x01;
	bitMask = bitMask << bitPosition;
	
	if (*bitSet & bitMask) {
		*bitSet = *bitSet ^ bitMask;
	}
}

// print signal status for each bit position
// 1 is on, 0 is off
void printbits(unsigned char bitSet) {
	/*
	 * bitSet: 8-bit unsigned integer, 0 - 255, representing signals
	 */

	for (int i = 0; i < 8; i++) {
		printf("Bit at position %d is set to %d\n", i, isset(bitSet, i));
	}
}

// performs a circular left shift by one position on a set of bits
void csl(unsigned char *bitSet) {
	/*
	 * *bitSet: address of an 8-bit unsigned integer, 0 - 255
	 */

	if (isset(*bitSet, 7)) {
		*bitSet = *bitSet << 1;
		addbit(bitSet, 0);
	}
	else {
		*bitSet = *bitSet << 1;
	}
	
}

// performs a circular right shift by one position on a set of bits
void csr(unsigned char *bitSet) {
	/*
	 * *bitSet: address of an 8-bit unsigned integer, 0 - 255
	 */

	if (isset(*bitSet, 0)) {
		*bitSet = *bitSet >> 1;
		addbit(bitSet, 7);
	}
	else {
		*bitSet = *bitSet >> 1;
	}
}

// check if at least one of two specified bit positions has a set bit
int ebs(unsigned char bitSet, int pos1, int pos2) {
	/*
	 * bitSet: 8-bit unsigned integer, 0 - 255, representing signals
	 * bitPosition: position of the first bit to check, 0 - 7
	 * bitPosition: position of the second bit to check, 0 - 7
	 * return: 1 if 1 or both of the bits are set; 0, otherwise
	 */

	if (isset(bitSet, pos1) || isset(bitSet, pos2)) {
		return 1;
	}

	return 0;
}

// check if both bits among two specified posiions are set
int etbs(unsigned char bitSet, int pos1, int pos2) {
	/*
	 * bitSet: 8-bit unsigned integer, 0 - 255, representing signals
	 * bitPosition: position of the first bit to check, 0 - 7
	 * bitPosition: position of the second position to check, 0 - 7
	 * return: 1 if both bits are set; 0, otherwise
	 */

	if (isset(bitSet, pos1) && isset(bitSet, pos2)) {
		return 1;
	}

	return 0;
}


