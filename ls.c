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


int filter(const struct dirent *temp){
	return 1;
}

int main(int argc,char* argv[]){

	struct dirent **list;
	int listnumber;
	errno=0;

	//printf("\n in ls");
	//char cmdline[200];
	//fgets(cmdline,sizeof(cmdline),stdin);

		listnumber=scandir("./", &list, filter, alphasort);
		if(listnumber<0){
			printf("\n%s\n",strerror(errno));
		}
		

		//printf("\n%s\n",arg);

		if(argc==2){
			if(strcmp(argv[1],"-a")==0){
			for(int i=0;i<listnumber;++i){
				printf("%s\t",list[i]->d_name);
			}
			}
			else if(strcmp(argv[1],"-1")==0){
				for(int i=0;i<listnumber;++i){
					
					if(list[i]->d_name[0]=='.'){
						continue;
					}
					else{
						printf("%s\n",list[i]->d_name);
					}
				}
			}
		}
		else if(argc==1){

			for(int i=0;i<listnumber;++i){
				if(list[i]->d_name[0]=='.'){
					continue;
				}
				else{
					printf("%s\t",list[i]->d_name);
				}
			}
		}
		printf("\n");
		if(errno) printf("\n%s\n",strerror(errno));
	
		
	return 0;
}