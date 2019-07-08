// read a file and count no of characters, no of words and no of lines in the file.

//File Handling

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
int check_v(char a){
	int chk=0;
	a = tolower(a);
	if(a=='a' ||a=='e' ||a=='i'||a=='o'||a=='u')
		chk=1;
	return chk;
}
void main(){
	int v=0,w=0,i=0,z,l=0;

// OPENING A FILE AND READING FROM IT
	FILE *rptr;
	char ch;
	rptr = fopen("text.txt","r");
	if(rptr == NULL){
		printf("\n\nFile not Found, Create a File in local directory and then run the program\n\n");
		exit(1);
	}
	printf("Content of File is : ");
	while((ch = getc(rptr)) != EOF){
		z=check_v(ch);
		if(z==1)
			v++;
		i++;
		if(ch==' ')
			w++;
		printf("%c",ch);
		if(ch == '.')
			l++;
	}
	if(l==0)
		l++;
	printf("\nNo of vowels is %d\nNo of characters is %d\nNo of white spaces are %d\nNo of lines are %d\n",v,i,w,l);
	fclose(rptr);
}
