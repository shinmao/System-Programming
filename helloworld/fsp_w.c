#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct contact{
	int id;
	char address[25];
};

int main(){
	
	int i;
	FILE *fsp;
	struct contact gmu[5];
	
	for(i=0;i<5;i++){
		printf("Please input the contact %d id and address?\n",i+1);
		printf("Input id: ");
		scanf("%d",&gmu[i].id);            // be careful that scanf need &
		printf("Input address: ");
		scanf("%s",&gmu[i].address);     // &
	}

	fsp = fopen("contact.txt","w");
	if(fsp == NULL){
		perror("error when open the file");
		exit(EXIT_FAILURE);
	}
	// int fprintf(FILE *stream, const char *format, ...)
	for(i=0;i<5;i++){
		fprintf(fsp, "%d %d %s\n", i+1, gmu[i].id, gmu[i].address);
	}

	fclose(fsp);
	
	return 0;
}
