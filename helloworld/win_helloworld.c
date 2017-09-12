#include <stdio.h>

int main(void){

		printf("helloworld\n");
		return 0;
}

int preFunc(void){

		printf("Here is the preFunc\n");
		return 0;
}

typedef int func(void);
#pragma data_seg("CRT$XIU")
static func *before[] = { preFunc };
