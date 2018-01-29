#include <stdio.h>
#define N 16

int factorial(int n);
int prime_or_not(int n);

int main(){
	int a,b;    // var in add function
	int n;  // var in exponent
	int result = 1;
	int f;  // var in factorial
	int p; // var in prime

	printf("Please enter two integer> ");
	scanf("%d %d", &a, &b);
	printf("The two number are %d and %d\n", a, b);
	printf("There sum is %d\n", a + b);

	printf("\t n \t 2^n\n");
	printf("\t====================\n");
	for(n=0;n<=N;n++){
		printf("\t %2d \t %5d\n", n, result);     // %nd can show with n bits
		result = result*2;
	}

	printf("Please choose the n of your factorial> ");
	scanf("%d",&f);
	printf("The result of factorial is %d\n", factorial(f));    // the result might overflow of the int type

	printf("Please decide the num is prime or not> ");
	scanf("%d",&p);
	printf("The fact that %d is prime is %d\n",p,prime_or_not(p));
	
	return 0;
}

int factorial(int n){
	int p,i = 1;
	int current = 1;
	for(i=1;i<=n;i++){
		current = current*i;
	}
	return current;
}

int prime_or_not(int n){
	int i;
	int result;
	for(i=2;i<n;i++){
		if(n%i == 0){
			result = 0;
			break;
		}else{
			result = 1;
		}	
	}
	return result;
}
