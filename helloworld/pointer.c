#include <stdio.h>

void ref(int *r){
	printf("ref r is %d\n",r);
}

void ar_ptr(int *l, char *str){
	int i;
	for(i = 0;i < strlen(str)-1;i++){ 
		printf("My input is %c at %p\n",str[i],&str[i]);
	}
}

int main(void){
	
	// reference pointer
	int a = 3;
	// address oprator
	int x = 4;
	int y = &x;
	int *z = &x;
	// 
	char buffer[12];
	int length;

	ref(a);
	printf("y is %d\n",y);
	printf("z is %d\n",*z);

	printf("Please input a string>\n");
	fgets(buffer,sizeof(buffer),stdin);
	length = strlen(buffer);
	ar_ptr(length,buffer);
	
	return 0;
}

