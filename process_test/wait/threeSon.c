#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

void errorFunc(){
	char* str="1234";
	str[7]='w';
}

void getSignal(int status){
	if(WIFEXITED(status)){
		printf("exit num:%d\n",WEXITSTATUS(status));
	}
	if(WIFSIGNALED(status)){
		printf("signal:%d\n",WTERMSIG(status));
	}
}

int main(){
	pid_t pid1=fork();
	if(!pid1){
		printf("I'm son1:%d\n",getpid());
		execlp("ps","ps","aux",NULL);
		return 0;
	}
	pid_t pid2=fork();
	if(!pid2){
		printf("I'm son2:%d\n",getpid());
		errorFunc();
		return 1;
	}
	pid_t pid3=fork();

	int status1,status2,status3;
	waitpid(pid1,&status1,0);
	waitpid(pid2,&status2,0);
	waitpid(pid3,&status3,0);
	
	getSignal(status1);
	getSignal(status2);
	getSignal(status3);
}
