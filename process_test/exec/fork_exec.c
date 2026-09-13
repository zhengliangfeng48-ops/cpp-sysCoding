#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(){
	pid_t pid=fork();
	if(pid==-1){
		perror("fork error");
		exit(1);
	}else if(pid==0){
		//execlp("ls","-l","-h",NULL);//错误写法
		//execlp("ls","ls","-l","-h",NULL);
		//execlp("date","date",NULL);
		//execl("./a.out","./a.out",NULL);
		execl("/bin/ls","ls","-l",NULL);
		perror("exec error");
		exit(1);
	}else if(pid>0){
		sleep(1);
		printf("I'm parent : %d\n",getpid());
	}
}
