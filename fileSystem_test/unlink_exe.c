#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>

int main(){
	int fd,ret;
	char *p="test of unlink\n";
	char *p2="after write something.\n";

	fd=open("temp.txt",O_RDWR|O_CREAT|O_TRUNC,0644);
	if(fd<0){
		perror("open temp error");
		exit(1);
	}
	
	ret=unlink("temp.txt");
	if(ret<0){
		perror("unlink error");
		exit(1);
	}

	ret=write(fd,p,strlen(p));
	if(ret==-1){
		perror("-----write error");
	}

	printf("hi! I'm printf\n");
	ret=write(fd,p2,strlen(p2));
	if(ret==-1){
		perror("-----write error");
	}

	printf("Enter anykey continue\n");
	getchar();

	p[3]='H';

	close(fd);
}
