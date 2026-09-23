#include<stdio.h>
#include<unistd.h>
#include<signal.h>

void sig_catch(int signo){
	printf("catch you!! %d\n",signo);
}

int main(){
	signal(SIGINT,sig_catch);
	while(1);
}
