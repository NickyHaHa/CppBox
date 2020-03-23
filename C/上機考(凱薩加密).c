#include<stdio.h>  
#include<string.h>
#define SIZE 52

int main()
{
	int num;
	scanf("%d",&num);
	char str[SIZE];
	//gets(str);
	scanf("%s",&str);
	
	for(int x=0;x<strlen(str);x++){
		if(str[x] >= 'A' && str[x] <= 'Z'){
			str[x]=((str[x]-'A')+num)%26+'A';

			if(str[x]<'A'){
				str[x]=str[x]+26;
			}
		}
		else if(str[x] >= 'a' && str[x] <= 'z'){
			str[x]=((str[x]-'a')+num)%26+'a';
			
			if(str[x]<'a'){
				str[x]=str[x]+26;
			}			
		}
	}
	puts(str);
return 0;
}	