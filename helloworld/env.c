#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[], char *envp[]){
	//int i;
	char *ptr, *getenv();
	printf("print my envp\n");
	/*for(i=0;envp[i]!=(char *)0;i++){
		printf("%s\n",envp[i]);
	}*/
	if((ptr = getenv("HOME")) == (char *)0){
		printf("HOME is not defined\n");
	}else{
		printf("HOME is %s",ptr);
	}
	exit(0);
	return 0;
}
