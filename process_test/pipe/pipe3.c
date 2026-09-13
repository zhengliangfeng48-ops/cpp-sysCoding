#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<fcntl.h>
#include<sys/wait.h>

int main(){
	int fd[2];
	int i,n;
	char buf[1024];

	int pipeRet=pipe(fd);
	if(pipeRet<0){
		perror("pipe error");
		exit(1);
	}
	
	for(i=0;i<2;++i){
		pid_t pid=fork();
		if(pid==-1){
			perror("pipe error");
		}
		if(pid==0){
			break;
		}
	}
	
	if(i==0){
		close(fd[0]);
		write(fd[1],"1.hello\n",strlen("1.hello\n"));
	}else if(i==1){
		close(fd[0]);
		write(fd[1],"2.world\n",strlen("2.world\n"));
	}else{
		close(fd[1]);
		sleep(1);
		n=read(fd[0],buf,1024);
		write(STDOUT_FILENO,buf,n);
		for(i=0;i<2;++i){
			wait(NULL);
		}
	}
}
