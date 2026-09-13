#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/mman.h>
#include<sys/wait.h>

int var=100;

int main(){
	int fd=open("/dev/zero",O_RDWR);

	int* p;
	p=(int*)mmap(NULL,490,PROT_READ|PROT_WRITE,MAP_SHARED,fd,0);
	//p=(int*)mmap(NULL,4,PROT_READ|PROT_WRITE,MAP_PRIVATE,fd,0);
	if(p==MAP_FAILED){
		perror("mmap error");
		exit(1);
	}
	close(fd);

	pid_t pid=fork();
	if(pid==0){
		*p=2000;
		var=1000;
		printf("child,*p=%d,var=%d\n",*p,var);
	}else{
		sleep(1);
		printf("parent,*p=%d,var=%d\n",*p,var);
		wait(NULL);

		int ret=munmap(p,4);
		if(ret==-1){
			perror("munmap error");
			exit(1);
		}
	}
}
