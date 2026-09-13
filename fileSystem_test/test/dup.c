#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

int main(int argc,char* argv[]){
	int fd=open(argv[1],O_RDONLY);

	int newfd=dup(fd);

	printf("newfd=%d\n",newfd);

	write(newfd,"1234567",7);
}
