#include<stdio.h>   
#include<string.h>
#define SIZE 50

void reverse(char *nPtr, char rev[]);
int main()
{
	char num[SIZE],rev[SIZE]={};
	gets(num);
	
	reverse(num,rev);
	
	if(strcmp(num,rev) == 0){
		printf(" Yes");
	}
	else{
		printf(" No");
	}
return 0;
}

void reverse(char *nPtr, char rev[])
{
	int x=0;
	while(*nPtr != '\0'){
		x++;
		nPtr++;
	}
	nPtr--;
	for(int y=0;y<x;y++){
		rev[y]=*nPtr;
		printf("%c",rev[y]);
		nPtr--;
	}
}