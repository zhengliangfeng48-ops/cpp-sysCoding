#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>

void sig_catch(int signo){
	if(signo==SIGINT){
		printf("catch you!! %d\n",signo);
		sleep(10);
	}/*else if(signo==SIGQUIT){
		printf("-----catch you!! %d\n",signo);
	}*/
}

int main(){
	struct sigaction act,oldact;

	act.sa_handler=sig_catch;
	sigemptyset(&(act.sa_mask));
	sigaddset(&(act.sa_mask),SIGQUIT);
	act.sa_flags=0;

	int ret=sigaction(SIGINT,&act,&oldact);
	if(ret==-1){
		perror("sigaction error");
		exit(1);
	}
	/*ret=sigaction(SIGQUIT,&act,&oldact);
	if(ret==-1){
		perror("sigaction error");
		exit(1);
	}*/

	while(1);
}
