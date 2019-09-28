#include<stdio.h>
 #include<string.h>

 void chk_label();
 void chk_opcode();
 void READ_LINE();
 struct optab
 {
   char  code[10],objcode[10];
 }myoptab[3]={
           {"LDA","00"},
           {"JMP","01"},
           {"STA","02"}
        };
 struct symtab{
           char symbol[10];
           int addr;
        }mysymtab[10];
 int startaddr,locctr,symcount=0,length;
 char line[20],label[8],opcode[8],operand[8],programname[10];
         void PASS1()
          {
             FILE *input,*inter;                  
             input=fopen("input.txt","r");              
             inter=fopen("inter.txt","w");
             printf("LOCATION LABEL\tOPERAND\tOPCODE\n");
             printf("_____________________________________");            
             fgets(line,20,input);
            READ_LINE();
            if(!strcmp(opcode,"START"))
            {
             startaddr=atoi(operand);
             locctr=startaddr;          
            strcpy(programname,label);
               fprintf(inter,"%s",line);
             fgets(line,20,input);
             }
            else
            {
              programname[0]='\0';
              startaddr=0;
              locctr=0;
            }
              printf("\n %d\t %s\t%s\t %s",locctr,label,opcode,operand);
               while(strcmp(line,"END")!=0)
              {
                   READ_LINE();
                   printf("\n %d\t %s \t%s\t %s",locctr,label,opcode,operand);
                   if(label[0]!='\0')chk_label();
                   chk_opcode();
                   fprintf(inter,"%s %s %s\n",label,opcode,operand);
                   fgets(line,20,input);
              }
           printf("\n %d\t\t%s",locctr,line);
           fprintf(inter,"%s",line);
           fclose(inter);
           fclose(input);
            }
      void PASS2()
      {
         FILE *inter,*output;
         char record[30],part[6],value[5];
         int currtxtlen=0,foundopcode,foundoperand,chk,operandaddr,recaddr=0;
         inter=fopen("inter.txt","r");
         output=fopen("output.txt","w");
         fgets(line,20,inter);
         READ_LINE();
         if(!strcmp(opcode,"START")) fgets(line,20,inter);
         printf("\n\nCorresponding Object code is..\n");
         printf("\nH^ %s ^ %d ^ %d ",programname,startaddr,length);
         fprintf(output,"\nH^ %s ^ %d ^ %d ",programname,startaddr,length);
         recaddr=startaddr; record[0]='\0';
         while(strcmp(line,"END")!=0)
              {
                        operandaddr=foundoperand=foundopcode=0;
                        part[0]= value[0]='\0';
                        READ_LINE();
       for(chk=0;chk<3;chk++)
        {
         if(!strcmp(opcode,myoptab[chk].code))
         {                  
         foundopcode=1;
         strcpy(part,myoptab[chk].objcode);
        if(operand[0]!='\0')
        {
        for(chk=0;chk<symcount;chk++)
        if(!strcmp(mysymtab[chk].symbol,operand))
        {
        itoa(mysymtab[chk].addr,value,10);
        foundoperand=1;
        }
        if(!foundoperand)strcpy(value,"err");
        }
        }
        }
         if(!foundopcode)
         {
                 if(strcmp(opcode,"BYTE")==0 || strcmp(opcode,"WORD")||strcmp(opcode,"RESB"))
                 {strcpy(value,operand);
                }}
         if((currtxtlen+strlen(value)+strlen(part))<=8)
         {
         strcat(record,"^");
         strcat(record,part);
         strcat(record,value);
         currtxtlen+=(strlen(value)+strlen(part));
         }
         else
         {
          printf("\nT^ %d ^%d ^%s",recaddr,currtxtlen,record);
          fprintf(output,"\nT^ %d ^%d ^%s",recaddr,currtxtlen,record);
          recaddr+=currtxtlen;
          currtxtlen=strlen(value)+strlen(part);
          strcpy(record,part);
          strcat(record,value);
         }
      fgets(line,20,inter);
         }  
            printf("\nT^ %d ^%d %s",recaddr,currtxtlen,record);
            fprintf(output,"\nT^ %d ^%d %s",recaddr,currtxtlen,record);
            printf("\nE^ %d\n",startaddr);
            fprintf(output,"\nE^ %d\n",startaddr);
            fclose(inter);
            fclose(output);
     }      
     void READ_LINE()
     {
       char buff[8],word1[8],word2[8],word3[8];
       int i,j=0,count=0;
        label[0]=opcode[0]=operand[0]=word1[0]=word2[0]=word3[0]='\0';
          for(i=0;line[i]!='\0';i++)
            {
           if(line[i]!=' ')buff[j++]=line[i];
           else
            {
            buff[j]='\0';
            strcpy(word3,word2);strcpy(word2,word1);strcpy(word1,buff);
            j=0;count++;
            }
            }
            buff[j-1]='\0';
            strcpy(word3,word2);
            strcpy(word2,word1);
            strcpy(word1,buff);
           switch(count)
             {
                   case 0:strcpy(opcode,word1);break;
                   case 1:{strcpy(opcode,word2);strcpy(operand,word1);}break;
                   case 2:{strcpy(label,word3);strcpy(opcode,word2);strcpy(operand,word1);}break;
             }
             }
       void chk_label()
          {
             int k,dupsym=0;
            for(k=0;k<symcount;k++)
            if(!strcmp(label,mysymtab[k].symbol))
            {
                              mysymtab[k].addr=-1;
                              dupsym=1;
                              break;
                              }
         if(!dupsym)
         {
         strcpy(mysymtab[symcount].symbol,label);
         mysymtab[symcount++].addr=locctr;
         }
         }
      void chk_opcode()
      {
      int k=0,found=0;
      for(k=0;k<3;k++)
              if(!strcmp(opcode,myoptab[k].code))
              {
                            locctr+=3;
                            found=1;
                            break;      
               }
        if(!found)
        {
             if(!strcmp( opcode,"WORD")) locctr+=3;
             else if (!strcmp(opcode,"RESW"))locctr+=(3*atoi(operand));
             else if(!strcmp(opcode,"RESB"))locctr+=atoi(operand);
         }
   }
         
         int main()
           {
             PASS1();
             length=locctr-startaddr;
             PASS2();                        
             getch();
           }   
