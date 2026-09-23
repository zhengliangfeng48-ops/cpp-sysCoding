#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

void *func(void){
	pthread_exit(NULL);
	return NULL;
}

void *tfn(void *arg){
	int i=(int)arg;
	sleep(i);
	if(i==2){
		//exit(0);				//退出进程
		//return NULL;			//返回到函数调用者
		//func();
		pthread_exit(NULL);
	}
	printf("--I'm %dth thread: pid=%d, tid=%lu\n",i+1,getpid(),pthread_self());
	return NULL;
}

int main(){
	int i;
	int ret;
	pthread_t tid;

	for(i=0;i<5;++i){	
		ret=pthread_create(&tid,NULL,tfn,(void*)i);
		if(ret){
			perror("pthread_create error");
			exit(1);
		}
	}
	sleep(i);
	printf("main: I'm main,pid=%d, tid=%lu\n",getpid(),pthread_self());
}
