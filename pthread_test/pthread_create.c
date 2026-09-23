#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>

void *tfn(void *arg){
	printf("thread: pid=%d,tid=%lu\n",getpid(),pthread_self());
	return NULL;
}

int main(){
	pthread_t tid;

	printf("main: pid=%d,tid=%lu\n",getpid(),pthread_self());

	int ret=pthread_create(&tid,NULL,tfn,NULL);
	if(ret<0){
		perror("pthread_create error");
		exit(1);
	}

	//sleep(1);
	pthread_exit((void*)0);
}
