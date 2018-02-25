#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]){

	char chr, filename[25];
	FILE *fsp;      // file stream pointer

	strcpy(filename,argv[1]);
	fsp = fopen(filename,"r");
	if(fsp == NULL){
		perror("Error while opening the file.\n");
		exit(EXIT_FAILURE);
	}
	printf("The content of the file %s are:\n",filename);
	// int fgetc(FILE *stream)
	while((chr = fgetc(fsp))!=EOF){       // please use () in the first one
		printf("%c",chr);
	}
	fclose(fsp);
	return 0;
}
