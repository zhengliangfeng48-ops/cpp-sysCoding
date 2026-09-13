#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>

int main(){
	int fd=open("ps.out",O_WRONLY|O_TRUNC|O_CREAT,0644);
	if(fd<0){
		perror("open error");
		exit(1);
	}

	dup2(fd,STDOUT_FILENO);

	pid_t pid=fork();
	if(pid==0){
		execlp("ps","ps","aux",NULL);
	}

	sleep(1);
	close(fd);
}
