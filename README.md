# S7-Lab-Language Processors Lab

## Program 1 : program1.c
- count no of characters, white spaces and vowels in a input line

[Link to the Code](https://github.com/vedanshdwivedi/S7-Lab1-Language_Processors-Lab/blob/master/program1.c)

![Output](https://github.com/vedanshdwivedi/S7-Lab1-Language_Processors-Lab/blob/master/program1.png?raw=true)

'''c
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
		if(((a[i]<'a')||(a[i]>'z'))&&((a[i]<'A')||(a[i]>'Z')))
			w++;
	}
	printf("\nThe no. of characters is %d\nThe no of vowels is %d\nThe no of white spaces is %d\n",n,v,w);
	printf("\n\nEnter a number to terminate program\n\n");	
	scanf("%d",&i); //use as getch();
}
'''


## Program 2 : program2.c
- read a file and count no of characters, no of words and no of lines in the file.
NOTE : Ensure that you have a file named 'text.txt' before executing

[Link to the Code](https://github.com/vedanshdwivedi/S7-Lab1-Language_Processors-Lab/blob/master/program2.c)

![Output](https://github.com/vedanshdwivedi/S7-Lab1-Language_Processors-Lab/blob/master/program2.png?raw=true)


## Program 3 : program3.c
- find words that contain at least a vowel from a file and store it in a table and then find the no. of occurances that particular word in the file by taking word from the table.
NOTE : Ensure that you have a file named 'test1.txt' before executing

[Link to the code](https://github.com/vedanshdwivedi/S7-Lab1-Language_Processors-Lab/blob/master/program3.c)

![Output](https://github.com/vedanshdwivedi/S7-Lab1-Language_Processors-Lab/blob/master/program3.png?raw=true)


## Program 4 : program4.c
- construct a finite automata which will identify the keywords like : if, for, while, do, else and identifiers from a file
NOTE : Ensure that you have a file named 'test2.txt' before executing which consists a C program

[Link to the Code](https://github.com/vedanshdwivedi/S7-Lab1-Language_Processors-Lab/blob/master/program4.c)

![Output](https://github.com/vedanshdwivedi/S7-Lab1-Language_Processors-Lab/blob/master/program4.png?raw=true)

## Program 5 : program5.c
- generate a symbol table from an assembly language program stored in a file using C program.
NOTE : Ensure that you have a file named 'ass1.txt' before executing which consists a C program


