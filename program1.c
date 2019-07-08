// count no of characters, white spaces and vowels in a input line
#include<stdio.h>
#include<string.h>
#include<ctype.h>
int check_v(char a){
	int chk=0;
	a = tolower(a);
	if(a=='a' ||a=='e' ||a=='i'||a=='o'||a=='u')
		chk=1;
	return chk;
}

int main(){
	char *a;
	int i,v=0,w=0,chk;
	printf("Enter the string : ");
	gets(a);
	int n = strlen(a);
	for(i=0;i<n;i++){
		chk = check_v(a[i]);
		if(chk==1)
			v++;
		if(a[i] == ' ')
			w++;	
	}
	printf("\nThe no. of characters is %d\nThe no of vowels is %d\nThe no of white spaces is %d\n",n,v,w);
	printf("\n\nEnter a number to terminate program\n\n");	
	scanf("%d",&i); //use as getch();
}
