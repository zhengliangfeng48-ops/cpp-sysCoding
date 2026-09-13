#include<stdio.h>
#include<stdlib.h>
#include<string.h>

double t1(){
	double cur=((double)(rand()%1000000000))/1000000000;
	while(1){
		double newNum=((double)(rand()%1000000000))/1000000000;
		if(newNum>cur){
			cur=newNum;
			break;
		}else{
			cur=newNum;
		}
	}
	return cur;
}

int main(int argc,char* argv[]){
	if(argc!=2){
		printf("参数输入错误\n");
		exit(1);
	}
	int N=atoi(argv[1]);
	printf("-----即将进行%d次迭代-----\n",N);
	double sum=0;
	for(int i=1;i<=N;++i){
		sum+=t1();
		printf("第%d次迭代结果：\t%.9f\n",i,sum/i);
	}
}
