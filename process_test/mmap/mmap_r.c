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
	struct student stu;
	
	int fd=open("test_map",O_RDONLY);
	if(fd==-1){
		perror("open error");
		exit(1);
	}

	struct student *p=mmap(NULL,sizeof(stu),PROT_READ,MAP_SHARED,fd,0);
	if(p==MAP_FAILED){
		perror("mmap error");
		exit(1);
	}
	
	close(fd);

	while(true){
		printf("id=%d,name=%s,age=%d\n",p->id,p->name,p->age);
		usleep(10000);
	}

	munmap(p,sizeof(stu));
}
