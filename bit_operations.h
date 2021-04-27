#ifndef BIT_OPERATIONS
#define BIT_OPERATIONS


//prototypes:

// basic bit operations and functions
int isset(unsigned char bitSet, int bitPosition);
void addbit(unsigned char *bitSet, int bitPosition);
void delbit(unsigned char *bitSet, int bitPosition);
void printbits(unsigned char bitSet);

//bonus bit operations and functions
void csl(unsigned char *bitSet);
void csr(unsigned char *bitSet);
int ebs(unsigned char bitSet, int pos1, int pos2);
int etbs(unsigned char bitSet, int pos1, int pos2);


#endif

