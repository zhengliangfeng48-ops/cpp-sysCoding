#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<pthread.h>

pthread_mutex_t mutex;

void* tfn(void* arg){
	srand(time(NULL));

	while(true){
		pthread_mutex_lock(&mutex);

		printf("hello ");
		sleep(rand()%1);
		printf("world\n");
		sleep(rand()%1);

		pthread_mutex_unlock(&mutex);
	}

	return NULL;
}

int main(){
	pthread_t tid;
	srand(time(NULL));

	int ret=pthread_mutex_init(&mutex,NULL);
	if(ret){
		fprintf(stderr,"mutex_init error:%s\n",strerror(ret));
		exit(1);
	}

	pthread_create(&tid,NULL,tfn,NULL);

	while(true){
		pthread_mutex_lock(&mutex);

		printf("HELLO ");
		sleep(rand()%1);
		printf("WORLD\n");
		sleep(rand()%1);

		pthread_mutex_unlock(&mutex);
	}

	pthread_join(tid,NULL);

	pthread_mutex_destroy(&mutex);
}

