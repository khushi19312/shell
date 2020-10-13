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

	if(argc==2){
		int r=remove(argv[1]);
		//printf("\n%d ",r);
		if(errno) printf("\n%s",strerror(errno));
	}
	else if(argc==3){
		if(strcmp(argv[1],"-i")==0){
			printf("\nrm: remove file '%s' (y/n)?",argv[2]);
			char ans[4];
			fgets(ans,sizeof(ans),stdin);
			if(strcmp(ans,"y")){
				int r=remove(argv[2]);
				//printf("\n%d ",r);
				if(errno) printf("\n%s",strerror(errno));
			}
		}
		else if(strcmp(argv[1],"-f")==0){
				int r=remove(argv[2]);

		}
	}
	if(errno) printf("\n%s\n",strerror(errno));


	return 0;
}