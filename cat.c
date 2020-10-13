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

/*int main(){
	FILE *f;
	char buf[2];
	f=fopen("hi.txt","r");
	char *l;
	int i;
	while((i=read(f,buf,1))>0)
	{
		printf("%c",buf[0]);
	}
	fclose(f);
	return 0;
}*/

//-E and -n

int main(int argc, char *argv[]) {

  FILE *file;
  
  char line[100];
  int count=0;
  
  /*for(int i=0;i<argc;++i){
    printf("%s\n",argv[i]);
  }*/

  if(argc==3){
    if(strcmp(argv[1],"-n")==0){
      file = fopen(argv[2], "r");
      char *tok;
      while(fgets(line, sizeof(line), file)){
        count++;
        if(strcmp(line,"\n")!=0){
        tok=strtok(line,"\n");
        printf("\t%d %s\n",count, tok);
        if(errno) printf("\n%s\n",strerror(errno));
        }
        else{
          printf("\t%d %s",count, line);
        }
      }
    }
    else if(strcmp(argv[1],"-E")==0){
      file = fopen(argv[2], "r");
      char *tok;
      while(fgets(line, sizeof(line), file)){
        //count++;
        if(strcmp(line,"\n")!=0){
        tok=strtok(line,"\n");
        printf("%s$\n", tok);
        if(errno) printf("\n%s\n",strerror(errno));
      }
      else{
         printf("$%s", line);
      }
      }
    }
  }
  else{

    file = fopen(argv[1], "rb");

    if(errno) printf("%s",strerror(errno));
    char *tok;
    while(fgets(line, sizeof(line), file)){
      //count++;
      if(strcmp(line,"\n")!=0){
        tok=strtok(line,"\n");
        printf("%s\n", tok);
        if(errno) printf("\n%s\n",strerror(errno));
      }
      else{
         printf("%s", line);
      }
      
      
    }
  }
  fclose(file);
  if(errno) printf("\n%s\n",strerror(errno));
  return(0);

}