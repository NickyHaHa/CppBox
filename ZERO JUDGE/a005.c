#include<stdio.h>  

int main()  
{     
	int inum;
	scanf("%d",&inum);
	
	int a[4];
	while(scanf("%d %d %d %d",&a[0],&a[1],&a[2],&a[3]) != EOF){
		if(a[1]-a[0] == a[2]-a[1] && a[3]-a[2] == a[1]-a[0]){
			int d=a[3]-a[2];
			a[4]=a[3]+d;
			
			printf("%d %d %d %d %d\n",a[0],a[1],a[2],a[3],a[4]);
		}
		
		else{
			int d=a[3]/a[2];
			a[4]=a[3]*d;
			
			printf("%d %d %d %d %d\n",a[0],a[1],a[2],a[3],a[4]);
		}
	}
return 0;  
}