#include<stdio.h>   

int main()
{
	int M,D;
	while(scanf("%d %d",&M,&D) != EOF)
	{
		int S = (M*2+D)%3;
		if(S == 0){
			printf("普通\n");
		}
		else if(S == 1){
			printf("吉\n");
		}
		else if(S == 2){
			printf("大吉\n");
		}
	}
return 0;
}