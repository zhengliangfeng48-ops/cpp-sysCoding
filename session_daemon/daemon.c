#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>

int main(){
	pid_t pid=fork();
	if(pid>0){
		exit(0);
	}

	pid=setsid();
	if(pid==-1){
		perror("setsid error");
		exit(1);
	}

	int ret=chdir("/home/zlf/cpp-sysCoding");
	if(ret==-1){
		perror("chdir error");
		exit(1);
	}

	umask(0022);

	close(STDIN_FILENO);
	int fd=open("/dev/null",O_RDWR);
	if(fd==-1){
		perror("open error");
		exit(1);
	}
	dup2(fd,STDOUT_FILENO);
	dup2(fd,STDERR_FILENO);

	while(1);//模拟守护进程业务
}
