#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){

	int count;
	
	printf("run this program %s in terminal with:\n", argv[0]);
	for(count = 1; count < argc; count++){
		printf("argument %d is %s\n", count, argv[count]);
	}

	return 0;
}
