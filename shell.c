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

char internalcommand[10][10]={"cd","echo","history","pwd","exit"};
char externalcommand[10][10]={"ls","cat","date","rm","mkdir"};
char CWD[200];

/*void getcmd(){

}*/

int isinternalCommand(char *cmd){
	for(int i=0;i<5;++i){
		if(strcmp(internalcommand[i],cmd)==0){
			return 1;
		}
	}
	return 0;
}
int isexternalCommand(char *cmd){
	for(int i=0;i<5;++i){
		if(strcmp(externalcommand[i],cmd)==0){
			return 1;
		}
	}
	return 0;
}
int cd(char *cmdline){

	char *tok;
	tok=strtok(cmdline," ");
	tok=strtok(0,"\n");
	if(strcmp(tok,"~")==0){
		chdir(CWD);
	}
	else if(strcmp(tok,"..")){
		int i;
		for(i=strlen(CWD)-1;i>=0;--i){
			if(CWD[i]=='\\'){
				break;
			}
		}
		char newd[200];
		for(int j=0;j<i;++j){
			newd[j]=CWD[i];
		}
		chdir(newd);
	}
	else{
		char cwd[200];
		strcpy(cwd,tok);
		chdir(cwd);
	}
	if(errno) printf("\n%s\n",strerror(errno));

}
int echo(char *cmdline){
	char *cmd;
	char *flag;
	char *tok;
	//char *line=strchr(cmdline," ");
	cmd=strtok(cmdline," ");
	flag=strtok(NULL," ");
	//tok+=1;
	//printf("%s\n",tok);

	if(strcmp(flag,"-E")==0){
		tok=strtok(NULL,"\n");
		//strcpy(line,tok);
		//tok=strtok(0,"\n");
		
		char printline[200];
		//printline=malloc(sizeof(char)*strlen(tok)+1);
		strcpy(printline,tok);
		printf("%s",printline);
		printf("\n");
	}
	else if(strcmp(flag,"-n")==0){
		tok=strtok(NULL,"\n");
		//tok=strtok(0,"\n");
		
		printf("%s",tok);
	}
	else{
		
		printf("%s ",flag);

		tok=strtok(NULL,"\n");
		
		
		printf("%s\n",tok);
	}
	if(errno) printf("\n%s\n",strerror(errno));


}
int history(char *cmdline){
	
	FILE *obj;
	obj=fopen("history.txt","r");
	char line[200];
	if(cmdline[7]=='\n'){
		int count=0;
		while(fgets(line,sizeof(line),obj)){
			count++;
			printf("%d %s",count,line);
		}
	}
	else{

		if(cmdline[9]=='c'){
			obj=fopen("history.txt","w");
		}	
		else{
			//char *offset;
			//offset=strchr(tok,' ');
			//offset++;
			int a=0;
			for(int i=11;i<strlen(cmdline)-1;++i){
				a=a*10;
				//rintf("%c",cmdline[i]);
				a+=(int)cmdline[i]-(int)'0';
			}
			//printf("%d\n",a);
			//int a=(int)offset[];
			FILE *f;
			f=fopen("temp.txt","w");
			int count=0;
			while(fgets(line, sizeof(line), obj)){
				count++;
				
				if(count==a){
					continue;
				}
				else{
					fputs(line,f);
				}
			}
			remove("history.txt");
			rename("temp.txt","history.txt");

		}

	}
	if(errno) printf("\n%s\n",strerror(errno));

}
int apphistory(char *cmdline){
	
	FILE *obj;
	obj=fopen("history.txt","a");
	fputs(cmdline,obj);
	fclose(obj);

}
int pwd(char *cmdline){
	if(cmdline[3]=='\n'){
		char cwd[200];
		getcwd(cwd, sizeof(cwd));
		printf("\n%s\n",cwd);
	}
	else{
		char *tok=strtok(cmdline," ");
		char *flag=strtok(NULL,"\n");
		if(strcmp(flag,"--help")==0){
			printf("\npwd: pwd [-LP]");
			printf("\n\tPrint the name of the current working directory.");
			printf("\n\n\tOptions:");
			printf("\n\t  -L\tprint the value of $PWD if it names the current working directory");
			printf("\n\t  -P\tprint the physical directory, without any symbolic links");
			printf("\n\n\tBy default, 'pwd' behaves as if '-L' were specified.");
			printf("\n\n\tExit Status:");
			printf("\n\tReturn 0 unless an invalid option is givenor the current directory cannot be read.\n");

		}

	}
	if(errno) printf("\n%s\n",strerror(errno));
	

}
void doexit(char *cmdline){
	if(cmdline[4]!='\n'){
		int a=(int)cmdline[5]-(int)'0';
		exit(a);
	}
	else{
		exit(0);
	}

}



int main (int argc, char **argv){

	char cmd[8];
	char cmdline[200];
	//printPrompt();
	char *prompt="shell";
	char *an=">>";

	getcwd(CWD,sizeof(CWD));
	

	do{
		
		printf("%s%s",prompt,an);

		fgets(cmdline, sizeof(cmdline), stdin); 
		char arguments[10][100];

		if(strlen(cmdline)==0){
			printf("\nError: command not found.");
			continue;
		}

		int j=0, c=0;
    	for(int i=0;i<(strlen(cmdline));i++){
        
	        if(cmdline[i]==' ' || cmdline[i]=='\n'  || cmdline[i]=='\0')
	        {
	            arguments[c][j]='\0';
	            c++;  
	            j=0;    
	        }
	        else
	        {
	            arguments[c][j]=cmdline[i];
	            j++;
	        }
    	}
    	strcpy(cmd,arguments[0]);
    	char *argv[c+1];
    	for(int i=0;i<c;++i){
    		//printf("\n%s",arguments[i]);
    		argv[i]=arguments[i];
    	}
    	argv[c]=NULL;
    	/*for(int i=0;i<c+1;++i){
    		printf("\n%s",argv[i]);
    		//argv[i]=arguments[i];
    	}*/


		int a;

		/*char *tok=strtok(cmdline," ");
		if(tok==NULL){
			tok=strtok(cmdline,"\n");
		}
		strcpy(cmd,tok);*/
		

		apphistory(cmdline);
		

		//cmd=checkcmd(cmdline);
 
		if (isinternalCommand(arguments[0])){
			if(strcmp(cmd,"cd")==0){
				cd(cmdline);
			}
			else if(strcmp(cmd,"echo")==0){
				echo(cmdline);
			}
			else if(strcmp(cmd,"history")==0){
				history(cmdline);
			}
			else if(strcmp(cmd,"pwd")==0){
				pwd(cmdline);
			}
			else if(strcmp(cmd,"exit")==0){
				doexit(cmdline);
			}


			if(errno){
				printf("\nError occured : %s",strerror(errno));
			}
		}

		
		
		else if(isexternalCommand(arguments[0])){	
			

			if(strcmp(arguments[0],"ls")==0){
				//printf("\nin here\n");
				pid_t Pid;	
				Pid = fork();
				if(Pid<0){
					printf("\nError: process cannot be created.");
				}

				else if(Pid==0){
					if(execv("/home/khushi/Desktop/shell/ls",argv)<0){
						printf("\nError: execvp failed: %s",strerror(errno));
						exit(1);
					}
					exit(0);
				}
				else{
					wait(NULL);
				}
			}
			else if(strcmp(arguments[0],"cat")==0){
				pid_t Pid;	
				Pid = fork();
				if(Pid<0){
					printf("\nError: process cannot be created.");
				}

				else if(Pid==0){
					if(execv("/home/khushi/Desktop/shell/cat",argv)<0){
						printf("\nError: execvp failed: %s",strerror(errno));
						exit(1);
					}
					exit(0);
				}
				else{
					wait(NULL);
				}
			}
			else if(strcmp(arguments[0],"mkdir")==0){
				pid_t Pid;	
				Pid = fork();
				if(Pid<0){
					printf("\nError: process cannot be created.");
				}

				else if(Pid==0){
					if(execv("/home/khushi/Desktop/shell/mkdir",argv)<0){
						printf("\nError: execvp failed: %s",strerror(errno));
						exit(1);
					}
					exit(0);
				}
				else{
					wait(NULL);
				}
			}
			else if(strcmp(arguments[0],"rm")==0){
				pid_t Pid;	
				Pid = fork();
				if(Pid<0){
					printf("\nError: process cannot be created.");
				}

				else if(Pid==0){
					if(execv("/home/khushi/Desktop/shell/rm",argv)<0){
						printf("\nError: execvp failed: %s",strerror(errno));
						exit(1);
					}
					exit(0);
				}
				else{
					wait(NULL);
				}
			}
			if(strcmp(arguments[0],"date")==0){
				pid_t Pid;	
				Pid = fork();
				if(Pid<0){
					printf("\nError: process cannot be created.");
				}

				else if(Pid==0){
					//printf("hi\n");
					if(execv("/home/khushi/Desktop/shell/date",argv)<0){
						printf("\nError: execvp failed: %s",strerror(errno));
						exit(1);
					}
					exit(0);
				}
				else{
					wait(NULL);
				}
			}
			
			
				
				
		}

		else {
			printf("\nError: command not found.");
		}
		

	}while(strcmp(cmd,"exit")!=0);
}