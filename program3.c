// find words that contain at least a vowel from a file and store it in a table and then find the no. of occurances that particular word in the file by taking word from the table.

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
	char arr[100][50];
	int as[100],n,chk,x,sup;
	int i=0;
	FILE *ptr;
	ptr = fopen("test1.txt","r");
	if(ptr == NULL){
		printf("\n\nCreate a file 'test1.txt' and run program again\n\nTERMINATING\n\n");
		exit(1);
	}
	// read file and store words in an array
	while(1){
		char r = getc(ptr);
		int k=0;
		r=tolower(r);
		while((r>='a')&&(r<='z')&&(r!=EOF)){
			arr[i][k++] = r;
			r=getc(ptr);
			r=tolower(r);
		}
		arr[i][k]=0;
		if(feof(ptr)){
			break;
		}
		i++;
	}
	int j;
	for(j=0;j<=i;j++){
		//for each word arr[j]
		chk=0;
		n=strlen(arr[j]);
		for(x=0;x<n;x++){
			sup=check_v(arr[j][x]);
			if(sup==1){
				as[j]=1;
				sup=0;
				break;
			}
		}
		if(as[j] != 1)
			as[j] = 0;
	}
	printf("\n\nWORDS CONTAINING VOWELS ARE : \n\n");
	for(j=0;j<=i;j++){
		if(as[j]==1){
			printf("%s\n",arr[j]);		
		}
	}
	fclose(ptr);
}
