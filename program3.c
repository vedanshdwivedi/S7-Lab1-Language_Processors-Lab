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

void file_content(char *a){
	FILE *r;
	char ch;
	r = fopen(a,"r");
	while((ch=getc(r))!=EOF){
		printf("%c",ch);
	}
	fclose(r);
}

void main(){
	char arr[100][50];
	int as[100];
	int i=0;
	FILE *ptr;
	ptr = fopen("test1.txt","r");
	if(ptr == NULL){
		printf("\n\nCreate a file 'test1.txt' and run program again\n\nTERMINATING\n\n");
		exit(1);
	}

	printf("\nCONTENT OF FILE : ");
	file_content("test1.txt");
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

	// Now the words from the file have been stored in an array arr[], size is i
	// For each word in arr[], perform the following check.
	// Check if the word has a vowel in it
	// if vowel exists, check whether the word exists in the vow[] array
	// if not, then add the word to the list, otherwise, continue
	int j,len,n,chk,m_chk,vc=0,cs;
	char vow[100][50];
	for(j=0;j<i;j++){
		// For each word check if it consists of a vowel.
		len=strlen(arr[j]);
		chk=0;cs=1;
		m_chk=0;
		for(n=0;n<len;n++){
			chk = check_v(arr[j][n]);
			if(chk==1)
				break;
		}
		// if vowel exists, search for word in vow[] array
		if(chk==1){
			for(n=0;n<=vc;n++){
				if(strcmp(arr[j],vow[n])==0)
					m_chk=1;
				if(m_chk==1)
					break;
			}
		}
		// if word does not exists i.e., m_chk=0, add the word in the list vow[]
		if((chk == 1) && (m_chk==0)){
			strcpy(vow[vc],arr[j]);
			vc++;
		}
	}
	printf("\nWords with vowels are : \n");
	// Now vow[] consists of 1 instance of word that has a vowel in it and arr[] consists of all words from file
	// for each word in vow, check for that word in arr[]
	for(j=0;j<vc;j++){
		chk=0;
		for(n=0;n<=i;n++){
			if(strcmp(arr[n],vow[j])==0)
				chk++;		
		}
		// Now we have the word and no of instances of that word.
		printf("%s \t %d\n",vow[j],chk);
		chk=0;
	}
	fclose(ptr);
}

