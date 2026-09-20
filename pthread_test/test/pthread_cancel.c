#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<pthread.h>
#include<unistd.h>

void *tfn(void *arg){
	while(1){
		printf("thread: pid=%d,tid=%lu\n",getpid(),pthread_self());
		sleep(1);
	}
	return NULL;
}

int main(){
	pthread_t tid;

	int ret=pthread_create(&tid,NULL,tfn,NULL);
	if(ret){
		fprintf(stderr,"pthread_create error: %s\n",strerror(ret));
		exit(1);
	}

	printf("main: pid=%d,tid=%lu\n",getpid(),pthread_self());

	sleep(5);

	ret=pthread_cancel(tid);
	if(ret){
		fprintf(stderr,"pthread_cancel error: %s\n",strerror(ret));
		exit(1);
	}

	while(1);

	pthread_exit((void*)0);
}
