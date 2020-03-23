#include<stdio.h> 
#include<string.h> 
 
#define SIZE 100 
 
int main() 
{ 
   char str[SIZE]; 
   gets(str); 
 
   char *tokenPtr=strtok(str,"() ,-"); 
     
   printf("%s ",tokenPtr);       //目前在位置no.1 
   
		while(tokenPtr != NULL){            //NULL='\0'  
			tokenPtr=strtok(NULL,"() ,-"); 	//找下一個位置
			
			if(tokenPtr != NULL){            
				printf("%s",tokenPtr); 
			} 
		} 
  puts(""); 
return 0; 
}