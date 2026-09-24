#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<fcntl.h>
#include<unistd.h>
#include<dirent.h>
#include<sys/stat.h>
#include<sys/wait.h>

#define WORK_DIR "/home/zlf/cpp-sysCoding/"
#define WORK_DIR2 "/home/zlf/cpp-sysCoding/process_test/"

void makeCleanAll(char* tarDir){
	DIR* dirp=opendir(tarDir);
	struct dirent* sdp;

	while((sdp=readdir(dirp))!=NULL){
		if(sdp->d_name[0]=='.'){
			continue;
		}
		char cur[1024];
		strcpy(cur,tarDir);
		strcat(cur,sdp->d_name);

		struct stat fileStat;
		stat(cur,&fileStat);

		if(S_ISDIR(fileStat.st_mode)){
			pid_t pid=fork();
			if(pid==0){
				chdir(cur);
				execlp("make","make","clean",NULL);
			}
			wait(NULL);
		}
	}
}

int main(){
	makeCleanAll(WORK_DIR);
	makeCleanAll(WORK_DIR2);
}
