#include <stdio.h>
#include <signal.h>
#include <string.h>

#define MAXARGS 20
#define ARGLEN 100

char *makestring(char *buf);
int execute(char *arglist[]);

int main(){
	char*arglist[MAXARGS + 1];
	int numargs = 0;
	char argbuf[ARGLEN];

	while(numargs < MAXARGS){
		printf("arg[%d]?", numargs);
		if(fgets(argbuf, ARGLEN, stdin))
	}
}
