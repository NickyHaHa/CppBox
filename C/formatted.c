#include<stdio.h>  
#include<math.h>  

int main()  
{  
    int N;  
    double num;  
    char A;  
    scanf("%c %d %lf",&A,&N,&num);  
      
    if(A == 'c'){  				//無條件進位
        num=num*pow(10,N);  
        int a=num+1;  
        double ans=a/pow(10,N);  
        printf("%.*lf\n",N,ans);          
    }  
    if(A == 'f'){  				//無條件捨去
        num=num*pow(10,N);  
        int a=num;  
        double ans=a/pow(10,N);  
        printf("%.*lf\n",N,ans);  
    }  
    if(A == 'r'){  				//四捨五入
        printf("%.*lf\n",N,num);  
    }  
return 0;  
}