#include <stdio.h> 
#include <stdlib.h>

#define NUM_OF_BITS 8

int main () {
	char *my_string;
	int input_int, args_assigned; 
	size_t nbytes = 100;
	short my_short, bit;
	int idx;
	/* This hex number is the same as binary 10000000 */ 
	short MASK = 0x80;
	args_assigned = 0; 
	input_int = -1;

	while ((args_assigned != 1) || (input_int < 0) || (input_int > 128))
	{
		puts ("Please enter an integer from 0 to 128."); 
		my_string = (char *) malloc (nbytes + 1);
		getline (&my_string, &nbytes, stdin);
		args_assigned = sscanf (my_string, "%d", &input_int); 
		if ((args_assigned != 1) ||(input_int < 0) || (input_int > 128)) puts ("\nInput invalid!");
	}

	my_short = (short) input_int; 
	printf ("Binary value = ");
	/*
	 * Convert decimal numbers into binary Keep shifting my_short by one to the left and test the highest bit. This does
	 * NOT preserve the value of my_short!
	 * */
	for (idx = 0; idx < NUM_OF_BITS; idx++) {
		bit = my_short & MASK; 
		printf ("%d\n", bit/MASK); 
		my_short <<= 1;
	}
	printf ("\n");
	return 0; 
}
