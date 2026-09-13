#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

int main(){
	pid_t pid=fork(),wpid;

	int status;

	if(pid==0){
		printf("---child,my id=%d,going to sleep 10s\n",getpid());
		sleep(10);
		printf("----------child die----------\n");
		return 73;
	}else if(pid>0){
		//wpid=wait(NULL);	//don't care
		wpid=wait(&status);
		if(wpid==-1){
			perror("wait error");
			exit(1);
		}

		if(WIFEXITED(status)){
			printf("child exit with %d\n",WEXITSTATUS(status));
		}
		if(WIFSIGNALED(status)){
			printf("child kill with signal %d\n",WTERMSIG(status));
		}

		printf("----------parent wait finish: %d\n",wpid);
	}else {
		perror("fork error");
		return 1;
	}
}
