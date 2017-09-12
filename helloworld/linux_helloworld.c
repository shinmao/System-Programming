#include <stdio.h>

__attribute__((constructor)) int beforeFunc(void){

		printf("Here is beforeFunc\n");
		return 0;
}

int main(void){
		
		printf("hello world\n");
		return 0;
}
