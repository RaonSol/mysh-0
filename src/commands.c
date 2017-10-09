#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include "commands.h"

int do_cd(int argc, char** argv) {
    if (!validate_cd_argv(argc, argv))
        return -1;
    chdir(argv[1]);
    return 0;
}

int do_pwd(int argc, char** argv) {
    if (!validate_pwd_argv(argc, argv))
        return -1;
    
    char pwd[8096]={'\0'};
    getcwd(pwd,8096);
    printf("%s\n",pwd);
    return 0;
}

int validate_cd_argv(int argc, char** argv) {
    if(strcmp(argv[0], "cd")==0 && argc==2) return 1;
    else return 0;
}

int validate_pwd_argv(int argc, char** argv) {
    if(strcmp(argv[0], "pwd")==0 && argc==1) return 1;
    else return 0;
}
