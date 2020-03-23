#include<stdio.h>
int Pn(int x);		//Pn=Perfect Numbers

int main()
{
	int input;
	scanf("%d",&input);
	Pn(input);
	return 0;
}

int Pn(int x)
{
	int a,b,c;					//a=2~input的數,b=因數,c=因數總和
	for(a=2;a<=x;a++){
		c=0;
			for(b=1;b<a;b++){
				if(a%b == 0){	//a%b的結果=0時，其b即為a的因數
				c=c+b;
				}
			}
		if(c == a){				//因數總和=原數時，即為P.N
			printf("%d\n",a);
		}
	}
return 0;
}