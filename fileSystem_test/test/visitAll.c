#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
#include<dirent.h>
#include<sys/stat.h>

void dfs(char* path){
	DIR* dirp=opendir(path);
	if(dirp==NULL){
		perror("opendir error");
		exit(1);
	}

	struct dirent* cur;
	while(cur=readdir(dirp)){
		if(cur->d_name[0]=='.'){
			continue;
		}

		struct stat sbuf;
		char curPath[1024];
		strcpy(curPath,path);
		strcat(curPath,"/");
		strcat(curPath,cur->d_name);
		int ret=stat(curPath,&sbuf);
		if(ret==-1){
			perror("stat error");
			exit(1);
		}

		if(S_ISDIR(sbuf.st_mode)){
			dfs(curPath);
		}else{
			printf("%20s\t\t%ld\n",cur->d_name,sbuf.st_size);
		}
	}
	
	closedir(dirp);
}

int main(int argc,char* argv[]){
	char* curFile;
	if(argc==1){
		curFile=".";
	}else if(argc==2){
		curFile=argv[1];
	}else {
		printf("参数输入有误\n");
		return 1;
	}
	struct stat sbuf;
	int ret=stat(curFile,&sbuf);
	if(ret==-1){
		perror("stat error");
		exit(1);
	}

	if(!S_ISDIR(sbuf.st_mode)){
		printf("%s\t%ld\n",curFile,sbuf.st_size);
		return 1;
	}
	dfs(curFile);
}
