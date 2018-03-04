# Bit Operation and Bit mask
In C language, we can make ```&```, ```|```, and ```^(XOR)```... several bit-operation on integers. Besides, we can also change our integer into binary format.  

## Bit Operation
```c
unsigned char c = 0;
int flag1 = 60;
int flag2 = 13;
c = flag1&flag2;
printf("%d",c);     // 12
```

## Bit mask
In the file of ```bitwise_op.c```, there is an interesting example to change integer to binary format
```c
my_short = (short) input_int;
	printf ("Binary value = ");
	/*
	 * Convert decimal numbers into binary Keep shifting my_short by one to the left and test the highest bit. This does
	 * NOT preserve the value of my_short!
	 * */
	for (idx = 0; idx < NUM_OF_BITS; idx++) {
		bit = my_short & MASK;
		printf ("%d\n", bit/MASK);       // here I print the bit from the first one
		my_short <<= 1;        // left shift
	}
/*** if input_int = 20 ***/
00010100
10000000
--------
00000000   /128 -> 0

00101000
10000000
--------
00000000   /128 -> 0
 . . . . . . .  -> 0
10100000
10000000
--------
10000000   /128 -> 1
Result-> 00010100
```
