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

### In file of ```*_helloworld.c```, what we want to do is to *add function before the main function*. :cold_sweat:

1.In Linux system, we will use the attribute of consturctor.

2.In window system, we will add function to the CRT table.
