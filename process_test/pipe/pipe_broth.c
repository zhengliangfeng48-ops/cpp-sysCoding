#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<fcntl.h>
#include<sys/wait.h>

int main(){
	int fd[2];
	int pipeRet=pipe(fd);
	if(pipeRet<0){
		perror("pipe error");
		exit(1);
	}
	
	int i;
	for(i=0;i<2;++i){
		pid_t pid=fork();
		if(pid==-1){
			perror("pipe error");
		}
		if(pid==0){
			break;
		}
	}
	
	if(i==2){
		close(fd[1]);
		close(fd[0]);
		wait(NULL);
		wait(NULL);
	}else if(i==0){
		close(fd[0]);
		dup2(fd[1],STDOUT_FILENO);
		execlp("ls","ls",NULL);		//输出到fd[1]了
		perror("execlp ls error");
	}else{
		close(fd[1]);
		dup2(fd[0],STDIN_FILENO);
		execlp("wc","wc","-l",NULL);	//从fd[0]输入
		perror("execlp wc error");
	}
}
