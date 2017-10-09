#include <string.h>
#include <stdlib.h>
#include "utils.h"

void mysh_parse_command(const char* command, int *argc, char*** argv)
{
    int idx=0;
    char cmdCpy[8096]={'\0'};
    char *parTmp;
    strcpy(cmdCpy, command);
    *argv=(char**)malloc(sizeof(char*));
    (*argv)[0]=(char*)malloc(sizeof(char));
    
    for(int i=0;cmdCpy[i]!='\0';i++)
        if(cmdCpy[i]=='\n'||cmdCpy[i]=='\t') cmdCpy[i]=' ';
    
    parTmp=strtok(cmdCpy, " ");
    for(idx=0;parTmp!=0;idx++)
    {
        *argv=(char**)realloc(*argv,sizeof(char*)*(idx+1));
        int size=(int)strlen(parTmp);
        (*argv)[idx]=(char*)malloc(sizeof(char)*(size+1));
        strcpy((*argv)[idx],parTmp);
        parTmp = strtok(NULL," ");
    }
    *argc=idx;
    
    if(**argv==NULL) strcpy((*argv)[0],"");
}
