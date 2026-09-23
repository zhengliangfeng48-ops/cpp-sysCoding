#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>
#include<sys/wait.h>

void catch_child(int signo){
	pid_t wpid;
	int status;
	//while((wpid=wait(NULL))!=-1){
	while((wpid=waitpid(-1,&status,0))!=-1){
		if(WIFEXITED(status)){
			printf("-----------catch child id=%d, ret=%d\n",wpid,WEXITSTATUS(status));
		}
	}
}

int main(){
	pid_t pid;

	//屏蔽SIGCHLD信号
	sigset_t myset;
	sigemptyset(&myset);
	sigaddset(&myset,SIGCHLD);
	sigprocmask(SIG_BLOCK,&myset,NULL);

	int i;
	for(i=0;i<15;++i){
		if((pid=fork())==0){
			break;
		}
	}

	if(i==15){
		struct sigaction act;
		act.sa_handler=catch_child;
		act.sa_flags=0;
		sigemptyset(&act.sa_mask);
		sigaction(SIGCHLD,&act,NULL);

		//解除屏蔽
		sigprocmask(SIG_UNBLOCK,&myset,NULL);

		printf("I'm parent,pid=%d\n",getpid());
		while(1);
	}else{
		printf("I'm child,pid=%d\n",getpid());	
		return i+1;
	}
}
