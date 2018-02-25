#include <stdio.h>
#include <stdlib.h>

struct contact {
	int id;
	char address[30];
};

int main(){
	
	struct contact *ptr;
	int i,n;
	printf("Enter n: ");
	scanf("%d",&n);

	ptr = (struct contact*)malloc(n*sizeof(struct contact));
	for(i=0;i<n;i++){
		printf("Enter id and address\n");
		scanf("%d %s",(char *)&(ptr+i)->id,(char *)&(ptr+i)->address);
	}		
	printf("show\n");
	for(i=0;i<n;i++){
		printf("%d %s\n",(ptr+i)->id,(ptr+i)->address);
	}
	
	return 0;
}
