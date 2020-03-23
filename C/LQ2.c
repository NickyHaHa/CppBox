#include<stdio.h>

int main()
{
	int a,b,c,xp;
	
	printf("Enter the level you wanna get(Max level is 100): ");
	scanf("%d",&a);
	
	if(a>100){
	printf("\nDoes not have such high level!!");
	}
	else{
	printf("And the number of xp now you are having: ");
	scanf("%d",&b);
	xp=(a-1)*(a-1)*(a-1)*10;
	c=xp-b;
	
	if(xp>b){
	printf("\nBefore you get the level\nYou are not enough xp: %d",c);
	}
	else{
		printf("\nYour level has already exceed the level you wanna get!!");
	}
}
	return 0;
}
