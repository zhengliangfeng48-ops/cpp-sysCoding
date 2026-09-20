#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<pthread.h>

void *tfn(void *arg){
	return (void*)74;
}

int main(){
	pthread_t tid;
	int ret=pthread_create(&tid,NULL,tfn,NULL);
	if(ret){
		perror("pthread_create error");
		exit(1);
	}
	
	int *retval;
	ret=pthread_join(tid,(void**)&retval);
	if(ret){
		perror("pthread_join error");
		exit(1);
	}

	printf("child thread exit with val=%d\n",(void *)retval);

	pthread_exit(NULL);
}
