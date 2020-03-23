#include<stdio.h>
int main()
{
	int a,b,c;			//c=放置用的box
	scanf("%d%d",&a,&b);
	
	while(a%b != 0){	//可以嘗試算算看
		c=b;
		b=a%b;
		a=c;
	}
	printf("%d\n",b);		//此時b即為gcd
	
	return 0;
}
