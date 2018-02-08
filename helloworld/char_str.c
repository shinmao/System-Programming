#include <stdio.h>
#include <string.h>

int main(){
	// In this program, we will seek the difference between 
	// scanf and fgets
	char buffer[32];
	int max = 26;
	printf("Please input some stings into buffer>\n");
	fgets(buffer,max,stdin);
	printf("In the buffer is: %s\n",buffer);
	printf("The length is %d\n",strlen(buffer));
	printf("Please input same strings again into buffer>\n");
	scanf("%s",&buffer);
	printf("with scanf in buffer> %s\n",buffer);
	printf("with scanf str length is %d\n",strlen(buffer));
	printf("You can also try to input string with space>\n");
	scanf("%s",&buffer);
	printf("with space in buffer, the string is %s\n",buffer);
	printf("the lenght of string now is %d\n",strlen(buffer));
	return 0;
}
