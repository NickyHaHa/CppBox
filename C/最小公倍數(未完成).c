#include<stdio.h>
int main()
{
	int a,b,l,c,d,e,f; //l=lcm
	scanf("%d%d",&a,&b);
	
if(a>b){
c=a%b;
	if(c!=0){
	d=b%c;
	}
		if(d==0){
		l=a*b/c;
			printf("%d\n",l);
		}	
	else if(d!=0){
	e=c%d;
		if(e==0){
		l=a*b/d;
			printf("%d\n",l);
		}
			else if(e!=0){
			f=d%e;
				if(f==0){
				l=a*b/e;
					printf("%d\n",l);
				}
			}
	}
}
			
else if(a<b){
c=b%a;
	if(c!=0){
	d=a%c;
	}
		if(d==0){
		l=b*a/c;
			printf("%d\n",l);
		}
	else if(d!=0){
	e=d%c;
		if(e==0){
		l=b*a/d;
			printf("%d\n",l);
		}
			else if(e!=0){
			f=e%d;
				if(f==0){
				l=b*a/e;
					printf("%d\n",l);
				}				
			}
	}
}
	
 return 0;
}
