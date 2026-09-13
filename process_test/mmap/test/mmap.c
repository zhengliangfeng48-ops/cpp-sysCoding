#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<sys/mman.h>
#include<fcntl.h>

int main(){
	int fd=open("testmap",O_RDWR|O_CREAT|O_TRUNC,0644);
	if(fd==-1){
		perror("open error");
		exit(1);
	}

	//lseek(fd,20,SEEK_END);
	//write(fd,"\0",1);
	ftruncate(fd,20);

	int len=lseek(fd,0,SEEK_END);

	char* p=mmap(NULL,len,PROT_READ|PROT_WRITE,MAP_SHARED,fd,0);
	if(p==MAP_FAILED){
		perror("mmap error");
		exit(1);
	}

	strcpy(p,"hello mmap\n");

	printf("----%s",p);

	int ret=munmap(p,len);
	if(ret==-1){
		perror("munmap error");
		exit(1);
	}
}
