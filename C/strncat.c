#include<stdio.h> 
#include<string.h> 
 
int main() 
{ 
 int l;       
    
   char str1[100]; 
    gets(str1);             //可用scanf讀字串 
   char str2[100]; 
    gets(str2); 
     
   scanf("%d",&l); 
     
   strncat(str1,str2,l); //把str2的前l的位置內容貼在str1後面 
   
   puts(str1); 
return 0; 
}