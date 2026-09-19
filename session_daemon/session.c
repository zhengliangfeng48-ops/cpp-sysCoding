#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(){
	pid_t pid;
	if((pid=fork())<0){
		perror("fork error");
		exit(1);
	}else if(pid==0){
		printf("child pid=%d\n",getpid());
		printf("Group id is %d\n",getpgid(0));
		printf("Session id is %d\n",getsid(0));

		sleep(10);
		setsid();

		printf("changed:\n");
		
		printf("child pid=%d\n",getpid());
		printf("Group id is %d\n",getpgid(0));
		printf("Session id is %d\n",getsid(0));

		sleep(20);
		exit(0);
	}
}
