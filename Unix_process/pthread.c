#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

pthread_mutex_t count = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t condition = PTHREAD_COND_INITIALIZER;

int countt = 0;
int exe = 0;
#define phase 10
#define ph1 3
#define ph2 6

void *add1(){
	for(;;){
		pthread_mutex_lock(&count);
		printf("here is %d in add1\n",exe++);
		pthread_cond_wait(&condition,&count);
		countt++;
		printf("pid1's counter is %d\n",countt);
		pthread_mutex_unlock(&count);
		if(countt >= phase)
			return NULL;
	}
}
void *add2(){
	for(;;){
		printf("***\n");
		pthread_mutex_lock(&count);
		if(countt<ph1 || countt>ph2){
			pthread_cond_signal(&condition);
		}else{
			countt++;
			printf("pid2's counter is %d\n",countt);
		}
		pthread_mutex_unlock(&count);
		if(countt>=phase)
			return NULL;
	}
}

int main(void){
	pthread_t pid1, pid2;
	pthread_create(&pid1,NULL,&add1,NULL);
	pthread_create(&pid2,NULL,&add2,NULL);
	pthread_join(pid1,NULL);
	pthread_join(pid2,NULL);
	printf("All threads finished\n");
}
