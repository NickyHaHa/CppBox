#include<stdio.h>  
#define SIZE 10  
  
int main()  
{     
    double Max=0,min=100000;  
    double ary[SIZE];  
    for(int x=0;x<SIZE;x++){  
        scanf("%lf",&ary[x]);  
    }  
    for(int y=0;y<SIZE;y++){  
        if(ary[y]>Max){  
            Max=ary[y];  
        }  
        else if(ary[y]<min){  
            min=ary[y];  
        }  
    }  
    printf("maximum:%.2lf\nminimum:%.2lf\n",Max,min);  
  
return 0;  
}