#include <stdio.h>

int f1(void);
int f2(int x, int a);
int a;

int main(){
	int a, b, c;
	a = 7;                 // main local
	b = f1();
	c = f2(a,b);
	printf("%d %d %d\n",a,b,c);
	return 0;
}
int f1(void){
	a = 12;       
	printf("%d",a);
	return(a+5);
}

int f2(int x, int a){
	printf("%d",a);
	return(x*a);
}
