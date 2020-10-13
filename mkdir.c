#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<errno.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include <dirent.h>
#include<sys/wait.h>

int main(int argc, char *argv[]){

	/*for(int i=0;i<argc;++i){
		printf("\n%s",argv[i]);
	}*/


	if(argc==2){
		mkdir(argv[1], (S_IRWXG | S_IRWXU));
		if(errno) printf("\n%s",strerror(errno));
	}
	if(argc==3){
		if(strcmp(argv[1],"-v")==0){
			mkdir(argv[2], (S_IRWXG | S_IRWXU));
			if(errno){ printf("\n%s\n",strerror(errno));}
			printf("\nmkdir: created directory '%s'",argv[2]);
		}
		else if(strcmp(argv[1],"-p")==0){
			struct stat s = {0};
			if(stat(argv[2], &s)== -1){
				mkdir(argv[2], (S_IRWXG | S_IRWXU));
				//printf("\nmkdir: created directory '%s'",argv[3]);
			}
			else{
				printf("\nError.");
				if(errno) printf("%s\n",strerror(errno));
			}
		}
	}
	if(errno) printf("\n%s\n",strerror(errno));
	


	return 0;
}