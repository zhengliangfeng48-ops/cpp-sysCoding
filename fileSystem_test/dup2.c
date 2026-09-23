#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main(int argc,char* argv[]){
	int fd1=open(argv[1],O_RDWR);
	int fd2=open(argv[2],O_RDWR);

	int fdret=dup2(fd1,fd2);
	printf("fdret=%d\n",fdret);

	int ret=write(fd2,"1234567",7);
	printf("ret=%d\n",ret);

	dup2(fd1,STDOUT_FILENO);

	printf("---------------------886\n");
}
