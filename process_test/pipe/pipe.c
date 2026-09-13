#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>

void sys_err(char* str){
	perror(str);
	exit(1);
}

int main(){
	int fd[2];
	int ret=pipe(fd);
	if(ret==-1){
		sys_err("pipe error");
	}
	
	pid_t pid=fork();
	if(pid>0){
		close(fd[0]);

		char* str="hello pipe\n";
		sleep(3);
		//write(fd[1],str,strlen(str));

		close(fd[1]);
	}else if(pid==0){
		close(fd[1]);

		char buf[1024];
		int ret=read(fd[0],buf,sizeof(buf));
		printf("child read ret=%d\n",ret);
		write(STDOUT_FILENO,buf,ret);

		close(fd[0]);
	}
}
