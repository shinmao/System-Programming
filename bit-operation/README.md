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

## Address of each argv
```c
int main(int argc,char **argv)   // pay attention to **argv instead of *argv
{
        int i;
        if(argc > 1){
                char *p = argv[1];          // argv[1] is "test 1 2"
                for(i=0;*p;p++,i++)
                        printf("argv[1][%d] = %c\n",i,argv[1][i]);     // argv[1][i] can show elements of "test 1 2"           
                fprintf(stdout,"%d\n",what(argv[1]));
        }else
                fprintf(stderr,"no~\n");
        return 0;
}

int what(char *str){      // what function is used to show the address of each elements
        char *s;
        printf("\"%s\" begins at address %p\n",str,str);
        for(s = str;*s;++s)          // if pointer is not null, add pointer by 1
                printf("s contains address: %p *s:%c\n",s,*s);
        return(s-str);
}
// OUTPUT: ./program "test 1 2"
argv[1][0] = t
argv[1][1] = e
argv[1][2] = s
argv[1][3] = t
argv[1][4] =  
argv[1][5] = 1
argv[1][6] =  
argv[1][7] = 2
"test 1 2" begins at address 0x7ffd79380239
s contains address: 0x7ffd79380239 *s:t
s contains address: 0x7ffd7938023a *s:e
s contains address: 0x7ffd7938023b *s:s
s contains address: 0x7ffd7938023c *s:t
s contains address: 0x7ffd7938023d *s: 
s contains address: 0x7ffd7938023e *s:1
s contains address: 0x7ffd7938023f *s: 
s contains address: 0x7ffd79380240 *s:2
8
```

## Reverse String with pointer
In fact, it is just print with reverse direction  
```c
int main()
{
        int size = 25;
        char str[size],*ptr;
        int len;
        printf("Please enter a string:\n");
        fgets(str,size,stdin);
        ptr = str;               // pointer is at the start of string
        while(*ptr)               // while is used to get the end pointer of string
                ptr++;     
        ptr--;
        len = ptr - str;                 // don't forget fgets would add NULL
        printf("Now we reverse:\n");
        while(ptr>=str)
                printf("%c",*ptr--);      // *ptr get the content from address
        return 0;
}
// OUTPUT: hello -> olleh
```
