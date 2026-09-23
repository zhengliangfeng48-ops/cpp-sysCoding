#include<stdio.h>
#include<stdlib.h>
#include<error.h>
#include<string.h>
#include<pthread.h>
#include<unistd.h>

void *tfn(void *arg){
	printf("thread: pid=%d,tid=%lu\n",getpid(),pthread_self());
	return NULL;
}

int main(){
	pthread_t tid;

	int ret=pthread_create(&tid,NULL,tfn,NULL);
	if(ret){
		//perror("pthread_create error");
		fprintf(stderr,"pthread_create error: %s\n",strerror(ret));
		exit(1);
	}

	ret=pthread_detach(tid);
	if(ret){
		//perror("pthread_detach error");
		fprintf(stderr,"pthread_detach error: %s\n",strerror(ret));
		exit(1);
	}

	//sleep(1);

	ret=pthread_join(tid,NULL);
	printf("join ret=%d\n",ret);
	if(ret){
		//perror("pthread_join error");
		fprintf(stderr,"pthread_join error: %s\n",strerror(ret));
		exit(1);
	}

	printf("main: pid=%d,tid=%lu\n",getpid(),pthread_self());

	pthread_exit((void*)0);
}
