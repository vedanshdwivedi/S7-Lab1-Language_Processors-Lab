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
	int as[100];
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



	// Words are stored in arr[] array, size of array is i
	int j,chk,len,x,vc=0,nl,z;
	char vow[100][50];
	for(j=0;j<i;j++){
		// Check each word for having vowel in it, if vowel is present, add it into another list
		chk = 0;
		len = strlen(arr[j]);
		for(x=0;x<len && chk == 0;x++){
			z = check_v(arr[j][x]);
			if(z == 1)
				chk++;
		}
		if(chk>0){
			// Vowel found, add to list
			nl= 0;
			z=0;
			for(x=0;x<nl;x++){
				if(strcmp(arr[j],vow[x]) == 0)
					z=1;
				if(z==1)
					break;
			}
			// if z=1, then word already exists....
			// if z=0, then add word to list
			if(z==0){
				strcpy(vow[vc],arr[j]);
				vc++;
			}
		}



		// vow contains all words with vowel, now print and count its no of occurances and print it
		for(j=0;j<vc;j++){
			chk=0;
			// word is in vow[j]
			for(x=0;x<i;x++){
				// checking words from all the words to count occurances
				if(strcpy(vow[j], arr[x]) == 0)
					chk++;
			}
			printf("Word - %s\t Occurances - %d\n",vow[j],chk);
		}
	fclose(ptr);
	}
}
