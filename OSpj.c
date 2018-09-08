//Jian Ma 1001532967
//cse 3320--001 Operation System
//project 01
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include <string.h>
#include <time.h>
#include <curses.h>

int main()
{
    pid_t child;
    DIR *d;
    struct dirent * de;
    int i, c, k;
    char s[256], cmd[256];
    time_t t;

    while(1){
    t = time(NULL);
    printf("TIme: %s\n", ctime(&t));

    getcwd(s, 200);
    printf("\nCurrent Directory: %s \n", s);

    d = opendir(".");
    c = 0;
    while((de = readdir(d))){
    if((de -> d_type) & DT_DIR)
        printf("( %d Directory: %s) \n", c++, de->d_name);
    }
    closedir(d);
    d = opendir(".");
    c = 0;
    while((de = readdir(d))){
        if(((de -> d_type) & DT_REG))
	      printf("(%d File: %s) \n", c++, de->d_name);
        if((c % 8) == 0){
            printf("Hit N to continue\n"); 
	    k = getchar();}  
    }
    closedir(d);
    printf("------------------------------------\n");
	printf("enter q for quit\nenter e for edit\nenter r for run\nenter c for change\n");
	printf("enter f for remove file\nenter d for display dirctory\nenter s for sort dirctory\n");
    c = getchar(); getchar();
    switch(c){
        case 'q': exit(0);
        case 'e': printf("which file you want to edit with?:");
                  scanf("%s",s);
                  strcpy(cmd,"pico ");
                  strcat(cmd, s);
                  system(cmd);
                  break;
        case 'r' : printf("Which file you want to run(which ./ sign)?:");
                  scanf("%s",cmd);
                  system(cmd);
		  printf("\n");
                  break;
        case 'c': printf("Which dircotry you want to Change?:");
                  scanf("%s", cmd);
                  chdir(cmd);
                  break;
	case 'f' : printf("Which file you want to remove?");
		   scanf("%s", cmd);
		   rmdir(cmd);
		  break;
	case 'd' : printf("Which dirctory you want to print? enter pwd name");
		   scanf("%s", cmd);
		   system(cmd);
		   break;
	case 's' : printf("Sort the file by size. entry");
		   scanf("%s", cmd);
		   system(cmd);
		   
    }


    }
}

