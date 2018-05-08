# Bit Operation and Bit mask
In C language, we can make `&`, `|`, and `^(XOR)`... several bit-operation on integers. Besides, we can also change our integer into binary format.  

## Bit Operation
```c
unsigned char c = 0;
int flag1 = 60;
int flag2 = 13;
c = flag1&flag2;
printf("%d",c);     // 12
```

## Bit mask
In the file of `bitwise_op.c`, there is an interesting example to change integer to binary format
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

## union v.s. struct
`union` is a type of data structure similar to struct.  
The difference is **union use same block of memory for each variables**.  
```c
int main(){

        union a
        {
                short i;
                char ch[2];
        };
        union a u;
        printf("Size of a is %lu\n",sizeof(u));       // Size of a is 2
        u.ch[0] = 3;
        u.ch[1] = 2;
        printf("%d,%d,%d\n",u.ch[0],u.ch[1],u.i);   // 3,2,515
        u.i = 520;
        printf("%d,%d,%d\n",u.ch[0],u.ch[1],u.i);   // 8,2,520

        return 0;
}
```
It is an interesting example of union. First, the size of a is 2 because vairables share same block of memory. Type of short and array of char are all 2 bytes. Second, we should imagine that `i` and `ch[2]` are same place now. Therefore, if we give `u.ch[0]` 3 and `u.ch[1]` 2, the number in memory would become `00000010 00000011`. That is also why `u.i` has the value of 515. In other words, if we give i 520, we just need to format it into binary set, then can find how much `u.ch[0]` and `u.ch[1]` are.  

## Big endian v.s. Little endian
Based on CPU instead of OS (based on hardware not software!  
Big endian: The `least` significant byte is stored at the `highest` memory address.  
Little endian: The `least` significant byte is stored at the `lowest` memory address.  

