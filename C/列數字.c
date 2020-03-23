#include<stdio.h>
int main()
{
	int a,b;
	scanf("%d",&a);
	
	for(b=1;b<=a;b++){			//make a loop		
			if(b%10==0){		//if b mod 10 = 0
			printf("%d\n",b);	//print the number and turn to next line
			}
		else{					//or just print the number
		printf("%d ",b);
		}
	}
		
	return 0;
}
