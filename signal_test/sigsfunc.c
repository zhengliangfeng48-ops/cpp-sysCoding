#include<stdio.h>
#include<unistd.h>
#include<signal.h>

void print_set(sigset_t *set){
	for(int i=1;i<32;++i){
		if(sigismember(set,i)){
			putchar('1');
		}else{
			putchar('0');
		}
	}
	printf("\n");
}

int main(){
	sigset_t set,oldset,pedset;
	sigemptyset(&set);
	sigaddset(&set,SIGINT);
	sigaddset(&set,SIGQUIT);
	sigaddset(&set,SIGBUS);
	sigaddset(&set,SIGKILL);

	int ret=sigprocmask(SIG_BLOCK,&set,&oldset);
	if(ret==-1){
		perror("sigprocmask error");
		return 1;
	}
	while(1){
		ret=sigpending(&pedset);
		if(ret==-1){
			perror("sigpending error");
			return 1;
		}
		print_set(&pedset);
		sleep(1);
	}
}
