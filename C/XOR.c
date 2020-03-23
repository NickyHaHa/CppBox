#include<stdio.h>  
#include<stdlib.h>
#define SIZE 50  
  
void change(char *xPtr);
  
int main()  
{  
	char str[SIZE];	
	gets(str);
		
	change(str);
	
	system("pause");		
    return 0;     
}  

void change(char *xPtr)
{
	int a=0,b;
	int key[]={4.07262316};
	int *kPtr=key;
	
	while(*xPtr != '\0'){
		a++;
		xPtr++;			//xPtr目前在'\0'
	}
	
	xPtr=xPtr-a;		//回到[0]
	
	printf("The Changed String Is :");
	for(b=a;b>0;b--){
		*xPtr=*xPtr^*kPtr;
		printf("%c",*xPtr);
		xPtr++;
	}
	
	xPtr=xPtr-a;
	
	printf("\nThe Double Changed String Is :");
	for(b=a;b>0;b--){
		*xPtr=*xPtr^*kPtr;
		printf("%c",*xPtr);
		xPtr++;
	}	
	puts("");
}		