#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<errno.h>
#include<time.h>
#include<string.h>


int main(int argc,char *argv[]){

	if(argc==1){
		struct tm *pointer;
		time_t t;
		char *ti;
		time(&t);
		pointer = localtime(&t);
		ti=asctime(pointer);
		if(ti[strlen(ti)-1]=='\n'){
			ti[strlen(ti)-1]='\0';
		}
		printf("%s",ti);
	}
	else{
		if(strcmp(argv[1],"-u")==0){
		struct tm *pointer;
		time_t t;
		char *ti;
		time(&t);
		pointer = gmtime(&t);
		ti=asctime(pointer);
		if(ti[strlen(ti)-1]=='\n'){
			ti[strlen(ti)-1]='\0';
		}
		printf("%s",ti);
		}
	}
	if(errno) printf("\n%s\n",strerror(errno));


	return 0;
}