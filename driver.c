// Test text...


// Driver program to test signal bit operations
// for signal processing using 8-bit values.

#include <stdio.h>
#include <stdlib.h>
#include "bit_operations.h"


int main() {
	
	// loop until user enters -1
	while (1) {
		//int selection = 0;
		int entry = 0;
		// user picks a bit operation to execute and test
		printf("Please enter Function (0 = IS, 1 = ADD, 2 = DEL, 3 = PRINT,\n");
		printf("4 = CSL, 5 = CSR, 6 = EBS, 7 = ETBS, 0r -1 to quit): ");
		scanf("%d", &entry);
		//int entry = selection;	// selection variable gets set to 0 after scanf("%x", %bitset) on line 37

		// control user input until a valid input is entered: (0 - 7, or -1)
		while (!(entry >= -1 && entry <= 7)) {
			printf("Invald entry\n");
			printf("Please enter Function (0 = IS, 1 = ADD, 2 = DEL, 3 = PRINT, or -1 to quit): ");
			scanf("%d", &entry);
		}

		// exit the program with a nice message if -1 is entered
		if (entry == -1) {
			printf("Exiting...\n");
			printf("Thank you!\n");
			exit(0);
		}
		
		// get a bitset from the user
		int bitSet = 0;
		printf("Enter bitset in hex (e.g. 0xFF for bitset 1111 1111): ");
		scanf("%x", &bitSet);
		printf("Bitset is: %p\n", bitSet);
		printf("\n");
		
		int bitPosition = 0;
		int bitPos1 = 0;
		int bitPos2 = 0;

		// execute the bit operation the user originally selected
		// See 'bit_operations.c' for list of functions and details.
		switch (entry) {
			case 0:
				printf("Enter bit position: ");
				scanf("%d", &bitPosition);
				printf("Bit in position %d was %d\n", bitPosition, isset(bitSet, bitPosition));
				printf("\n");
				break;
			case 1:
				printf("Enter bit position: ");
				scanf("%d", &bitPosition);

				printf("Old bitset %p.\n", bitSet);
				addbit(&bitSet, bitPosition);
				printf("New bitset %p\n", bitSet);
				printf("\n");

				break;
			case 2:
				printf("Enter bit position: ");
				scanf("%d", &bitPosition);
				
				printf("Old bitset %p.\n", bitSet);
				delbit(&bitSet, bitPosition);
				printf("New bitset %p\n", bitSet);
				printf("\n");

				break;
			case 3:
				printbits(bitSet);
				printf("\n");
				break;
			case 4:
				printf("Old bitset %p.\n", bitSet);
				csl(&bitSet);
				printf("New bitset %p\n", bitSet);
				printf("\n");

				break;
			case 5:
				printf("Old bitset %p.\n", bitSet);
				csr(&bitSet);
				printf("New bitset %p\n", bitSet);
				printf("\n");

				break;
			case 6:
				printf("Enter two bit positions seperated by a space (e.g. 0 7): ");
				scanf("%d %d", &bitPos1, &bitPos2);
				
				if (ebs(bitSet, bitPos1, bitPos2)) {
					printf("One or both of the bits in positions %d or %d is set\n", bitPos1, bitPos2);
				}
				else {
					printf("Neither of the bits in position %d, nor %d is set\n", bitPos1, bitPos2);
				}
				printf("\n");

				break;
			case 7:
				printf("Enter two bit positions seperated by a space (e.g. 0 7): ");
				scanf("%d %d", &bitPos1, &bitPos2);
				
				if (etbs(bitSet, bitPos1, bitPos2)) {
					printf("Both of the bits in positions %d and %d is set\n", bitPos1, bitPos2);
				}
				else {
					printf("One or both of the bits in position %d and %d is reset\n", bitPos1, bitPos2);
				}
				printf("\n");

				break;
			default:
				break;
		}
	}

	return 0;
}

void test() {
	int x = 0;
}


