#include <stdio.h>
#include <stdlib.h>
#include<string.h>
    int main(int argc, char **argv) {
    char sign;int myNumber; int c; int boolSign=0; int boolFile =0;FILE* fp;int j=1;
    for(;j<argc;j++){
        if(strcmp(argv[j],"-i")!=0){
            if((char)argv[j][0]=='+'||(char)argv[j][0]=='-'){
            sign=(char)argv[j][0];         
            myNumber=(char)argv[j][1]-'0';
            boolSign=1;
        }}
        if(strcmp(argv[j],"-i")==0){
           fp=fopen(argv[j+1],"r");
            boolFile=1;   
        }
        
    }
    if(boolFile!=0){
    if(fp) {
    while ((c = getc(fp)) != EOF){
      if(c>=65 && c<=90){
            c=c+32;
        }
        if(c>=97&&c<=122){
            if(boolSign!=0){
            if(sign=='+')
                c=c+myNumber; 
            else c=c-myNumber;
        }
        if(c<97)
            c=c+26;
        if(c>122)
            c=c-26;
        }
        putchar(c);}
    fclose(fp);
    return 0;
    }
    else {
        perror("FILE cannot be opened for reading!\n");
        return -1;
    }
    }
    
    while((c=getc(stdin))!=EOF){
        if(c>=65 && c<=90){
            c=c+32;
        }
        if(c>=97&&c<=122){
            if(boolSign!=0){
            if(sign=='+'){
                
                c=c+myNumber;} 
            else c=c-myNumber;
        }
        if(c<97)
            c=c+26;
        if(c>122)
            c=c-26;
        }
    
        printf("%c",c);
        }

    
    printf("\n");
    return 0;
    } 
