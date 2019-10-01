#include<stdio.h>
#include<string.h>

int optab(char a[]){
    if(strcmp(a,"START")==0)
        return 1;
    if(strcmp(a,"STA")==0)
        return 2;
    if(strcmp(a,"JMP")==0)
        return 3;
    if(strcmp(a,"LDA")==0)
        return 4;
    if(strcmp(a,"RESB")==0)
        return 5;
    if(strcmp(a,"END")==0)
        return 6;
}

int count_terms(char *line){
    int count=0;
    for(int i=0;i<strlen(line);i++){
        if(line[i]==' ')
            count++;
    }
    return count+1;
}

int main(){
    FILE *fp,*fptr;
    fp = fopen("input.txt","r");
    fptr = fopen("inter.txt","w");
    int t;
    char line[17],label[5],opcode[5],operand[5];
    while(fgets(line,sizeof(line),fp)!=NULL){
        t=count_terms(line);
        printf("\n%d : %s",t,line);
    }
    fclose(fp);
    fclose(fptr);
}
