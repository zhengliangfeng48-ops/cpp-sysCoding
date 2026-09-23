#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<pthread.h>

struct thrd{
	int var;
	char str[256];
};

/*
void *tfn(void *arg){
	struct thrd *tval;
	tval=malloc(sizeof(tval));
	tval->var=100;
	strcpy(tval->str,"hello thread");

	return (void*)tval;
}
*/

/*
void *tfn(void *arg){
	struct thrd tval;
	tval.var=100;
	strcpy(tval.str,"hello thread");

	return (void*)&tval;
}
*/

void *tfn(void *arg){
	struct thrd *tval=(struct thrd*)arg;
	tval->var=100;
	strcpy(tval->str,"hello thread");

	return (void*)tval;
}

int main(){
	pthread_t tid;
	struct thrd *arg;
	int ret=pthread_create(&tid,NULL,tfn,(void*)&arg);
	if(ret){
		perror("pthread_create error");
		exit(1);
	}
	
	struct thrd *retval;
	ret=pthread_join(tid,(void**)&retval);
	if(ret){
		perror("pthread_join error");
		exit(1);
	}

	printf("child thread exit with var=%d,str=%s\n",retval->var,retval->str);

	pthread_exit(NULL);
}
