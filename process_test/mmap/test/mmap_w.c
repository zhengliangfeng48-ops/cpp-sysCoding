#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/mman.h>

struct student{
	int id;
	char name[256];
	int age;
};

int main(){
	struct student stu={1,"xiaoming",18};
	
	//int fd=open("test_map",O_RDWR|O_CREAT|O_TRUNC,0644);
	int fd=open("test_map",O_RDWR);
	if(fd==-1){
		perror("open error");
		exit(1);
	}

	ftruncate(fd,sizeof(stu));

	struct student *p=mmap(NULL,sizeof(stu),PROT_READ|PROT_WRITE,MAP_SHARED,fd,0);
	if(p==MAP_FAILED){
		perror("mmap error");
		exit(1);
	}
	
	close(fd);

	while(true){
		memcpy(p,&stu,sizeof(stu));
		stu.id++;
		sleep(2);
	}

	munmap(p,sizeof(stu));
}
