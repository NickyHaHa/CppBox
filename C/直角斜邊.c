#include<stdio.h>
#include<math.h>
int main()
{
	int a,b,c;
	scanf("%d%d",&a,&b);
	
	c=a*a+b*b;
	float A=sqrt(c);
	printf("%.2f\n",A);
	
	return 0;
}
