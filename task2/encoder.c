#include <stdio.h>
#include <stdlib.h>
#include<string.h>
    int main(int argc, char **argv) {
    char sign;int myNumber; int c; int boolSign=0; int boolFileOUT =0;FILE* fpOUT;int j=1; char str[30];int boolFileRead =0;FILE* fpRead;
    for(;j<argc;j++){
        if(strcmp(argv[j],"-o")!=0&&strcmp(argv[j],"-i")!=0){
            if((char)argv[j][0]=='+'||(char)argv[j][0]=='-'){
            sign=(char)argv[j][0];         
            myNumber=(char)argv[j][1]-'0';
            boolSign=1;
        }}
        if(strcmp(argv[j],"-o")==0){
            printf("Enter output file:\n");
            fgets(str,30,stdin);int k=0;
            for(;k<strlen(str);k++){
                if(str[k]=='\n')
                    str[k]=0;
            }
            fpOUT=fopen(str,"w");
            boolFileOUT=1;   
        }
        if(strcmp(argv[j],"-i")==0){
            fpRead=fopen(argv[j+1],"r");
            boolFileRead=1;   
        }
        
    }
    
    if(boolFileRead!=0&&boolFileOUT!=0){
        if(fpOUT){
            if(fpRead){
        while ((c = getc(fpRead)) != EOF){
      if(c>=65 && c<=90){
            c=c+32;
        }
        if(c>=97&&c<=122){
            if(boolSign!=0){
            if(sign=='+'){
                c=c+myNumber;}
            else {c=c-myNumber;}
        }
        if(c<97)
            c=c+26;
        if(c>122)
            c=c-26;
        }
        fprintf(fpOUT,"%c",c);}
    fclose(fpOUT);
    fclose(fpRead);
    return 0;
    }else {
        perror("FILE cannot be opened for writing/reading!\n");
        return -1;
        }
            
        }
    else {
        perror("FILE cannot be opened for writing/reading!\n");
        return -1;
        }
    }
    
     if(boolFileRead==0&&boolFileOUT!=0){
         if(fpOUT){
             printf("Enter text to encode:\n");
        while ((c = getc(stdin)) != EOF){
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
        fprintf(fpOUT,"%c",c);}
    fclose(fpOUT);
    return 0;
    }
    else {
        perror("FILE cannot be opened for writing!\n");
        return -1;
        }
    } 
    
     if(boolFileRead!=0&&boolFileOUT==0){
         if(fpRead) {
        while ((c = getc(fpRead)) != EOF){
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
        putchar(c);}
    fclose(fpRead);
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
