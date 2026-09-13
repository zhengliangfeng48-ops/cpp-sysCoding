#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(int argc,char* argv[]){
	if(argc!=2){
		printf("input error\n");
		return 1;
	}

	pid_t parentPID=getpid();
	int n=atoi(argv[1]);

	for(int i=0;i<n;++i){
		pid_t curPID=getpid();
		if(curPID==parentPID){
			int curSonPID=fork();
			if(curSonPID==0){
				printf("The %dth SonPID = %d\n",i+1,getpid());
			}
		}else{
			break;
		}
	}
}
