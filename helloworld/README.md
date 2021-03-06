### In file of ```calculator.c```, there is the basic practice.

Some concepts:  

1. symbolic constant
```c
#define N 16
```

2. printf vs scanf  
```c
printf("Number is %d",p);   // print the value of p
printf("Number is %3d",p);   // show p with 3 digits
printf("Number is %d",&p);  // decimal address of p
scanf("%d", &p);       // put the input into value of p
```

3. Function  
```c
int function(int n);
int main(){return 0};
int function(int n){return};
```  
declare the function before use.  

### In file of `pointer.c`, there is a challenge of pointer to new C baby:  
I will start from some symbols  
`*` means dereference, get value from the address.  
`&` has two kinds of meaning, reference operator or address operator:  
* reference operator  
```
int N = 3;
int &M = N;   
// M and N point to the same block of memory
```
* address operator  
```c
int N = 3;
int M = &N;
// M get the address of N
int *M = &N;
// with dereference pointer, we can get the value from the address
```
We can also get the content of array with pointer.  
Here is the print out result of `pointer.c`:  
```c
ref r is 3
y is -1722773048
z is 4
Please input a string>
hello
My input is h at 0x7ffd995091e0
My input is e at 0x7ffd995091e1
My input is l at 0x7ffd995091e2
My input is l at 0x7ffd995091e3
My input is o at 0x7ffd995091e4
// If you want to print the whole string in the buffer at one time, you can
printf("My whole input is %s\n",str);
```

### In file of `ptr_struct.c`, we also can access structure with pointer!
```c
struct A{
  int id;
  char hello[10];
};
struct A a1;
struct A a2;
struct A *b2 = &a2;    // use pointer to access structure
a1.id = 1;
b2->hello = "hello";    // different way to access
```
Memory of the elements in structure might not be contigious because there could be some padding bytes...  

### In file of `char_str.c`, pay attention to some string operation!
`strcpy()` would paste `\0` at the end of string  
```c
char str[12];
strcpy(str,"hello world");
// In fact, we can just only put string of length 11 bytes into it
// because the str[12] might be \0
```  
`strlen()` would take words before `\0` into count  
The following is the result of the file
```c
Please input some stings into buffer>
helloworld
In the buffer is: helloworld

The length is 11
Please input same strings again into buffer>
helloworld
with scanf in buffer> helloworld
with scanf str length is 10
You can also try to input string with space>
hello world
with space in buffer, the string is hello
the lenght of string now is 5
```
Q1: Why the same string can cause different `strlen()` with `fgets()` and `scanf()`?  
Because fgets would add one more null pointer to the eof; therefore; the result of fgets would more than scanf by one.  
Q2: Why the scanf only get "hello" in the last question?  
Because scanf **cannot** accept space!  

### In file of `argv.c`, we can learn how to get argument of program
```c
int main(int argc, char *argv[]){
       // the argc can get the count of argument including program itself
       // the all argument is stored in argv[]
}
```

### In file of `fsp.c`, we use the file stream pointer to `fopen()`
read file -> error if no such file -> print the file content  
Here we take operation on file stream pointer on high-level, another important thing is **file descriptor** on low-level.  
File descriptor is a non negative number returned by kernel when we open a file in process.  
In user application area, the **file descriptor table** would match to **system file table** in kernel, then to the entry in **inode table**. Be careful, there might be symbolic link in fd table, but the link in **inode table** must be unique!  
Every program has three common fd: 0: `stdin`, 1: `stdout`, 2: `stderr`

### In file of `fsp_w.c`, we write into file with `fprintf()`
`fprintf(ptr, "format string", content);`  

### `mal_stu.c` is interesting example to malloc our struct!!
`printf("%s",(ptr+i)->c);`

### `env.c` show how to print the system variable
```c
if((ptr = getenv("HOME")) == (char *)0){
		printf("HOME is not defined\n");
	}else{
		printf("HOME is %s",ptr);
	}
```
the code above shows how to print out specific env variable.  

### `scope_rule.c` show an important concept of scope
```c
int a;         // global 
int main(){
	int a, b, c;
	a = 7;                 // main local
	b = f1();
	c = f2(a,b);
	printf("%d %d %d\n",a,b,c);
	return 0;                    }
int f1(void){
	a = 12;
	printf("%d",a);
	return(a+5);     }
int f2(int x, int a){
	printf("%d",a);
	return(x*a);      }
/** OUTPUT: 12 17 7 17 119 **/
```
local variable and global variable are in different scope.  
12 comes from the f1 function print, here f1 change the global variable a to 12. Second, main function pass x=7, a=17 into f2 function. Therefore, f2 print out 17 as a. At the end, main function print out variable in his local scope.

### In file of `*_helloworld.c`, what we want to do is to *add function before the main function*. :cold_sweat:

1.In Linux system, we will use the attribute of consturctor.

2.In window system, we will add function to the CRT table.
