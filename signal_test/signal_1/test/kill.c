#include<stdio.h>
#include<unistd.h>
#include<signal.h>

int main(){
	pid_t pid=fork();
	if(pid>0){
		while(true){
			printf("parent,pid=%d\n",getpid());
			sleep(1);
		}
	}else if(pid==0){
		printf("child pid=%d,ppid=%d\n",getpid(),getppid());
		sleep(10);
		kill(0,SIGKILL);
	}
}
