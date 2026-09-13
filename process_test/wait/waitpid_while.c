#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

int main(){
	int i;
	pid_t pid,wpid;

	for(i=0;i<5;++i){	
		pid=fork();
		if(pid==0){	
			break;
		}
	}

	if(i==5){
		/*
		wpid=waitpid(-1,NULL,0);
		while(wpid){
			sleep(1);
			printf("wait child %d \n",wpid);
			wpid=waitpid(-1,NULL,0);
		}
		*/
		wpid=waitpid(-1,NULL,WNOHANG);
		while(wpid!=-1){
			if(wpid>0){
				printf("wait child %d\n",wpid);
			}else{
				sleep(1);
			}
			wpid=waitpid(-1,NULL,WNOHANG);
		}
	}else{
		sleep(i);
		printf("I'm %dth child,pid=%d\n",i+1,getpid());
	}
}
