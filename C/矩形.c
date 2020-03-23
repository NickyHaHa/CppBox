#include<stdio.h>  
void A(int x,int y,char z);  
  
int main()  
{  
    int a,b;  
    char c;							//字元
    scanf("%d %d %c",&a,&b,&c);		//%d與%d之間分開!
    A(a,b,c);						//from function
      
    return 0;  
}  
  
void A(int x,int y,char z)  		//function
{  
    int q,w;  
    for(q=1;q<=x;q++){  			//make the 矩形 in function
        for(w=1;w<=y;w++){  
            printf("%c",z);  
        }  
        printf("\n");  
    }  
}  