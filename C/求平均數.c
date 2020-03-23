#include<stdio.h>
int main()
{
	int a,t,c,g;				//a=average,t=total,c=counter
	
	t=0;						//at the beginning,total and counter = 0
	c=0;
	
	while(g!=0){				//in condition of g not equal to 0,loop will continue
		scanf("%d",&g);
		t=t+g;					
		c++;					//count the times of loop
		if(g==0)				//if g = 0,loop will stop
			break;
	}
	
	a=t/(c-1);					
	printf("%d\n",a);
	
	return 0;
}
