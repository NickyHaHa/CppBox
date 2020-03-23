#include<stdio.h>  

void value(int a, int b);
void reference(int *xPtr, int *yPtr);
  
int main()  
{  
	int A,B;
	scanf("%d %d",&A,&B);
	
	value(A,B);
	printf("ans=%d\n",A);
	
	reference(&A,&B);
	printf("%d\n",A);
	
return 0;
}

void value(int a, int b) //only change 3Mtap
{
	a=a+b;
}

void reference(int *xPtr, int *yPtr) //change reference
{	
	*xPtr=*xPtr+*yPtr;
}