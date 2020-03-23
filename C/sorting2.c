#include<stdio.h>  
#define SIZE 100
int main()  
{     
	int in,even[SIZE],odd[SIZE],elen=0,olen=0;
	
	while(scanf("%d",&in) != EOF){
		if(in%2 == 0){
			even[elen++]=in;
		}	
		else{
			odd[olen++]=in;
		}
	}
	
	for(int pass=0;pass<elen;pass++){
		for(int c=0;c<elen-1;c++){
			if(even[c]>even[c+1]){
				int hold=even[c];
				even[c]=even[c+1];
				even[c+1]=hold;
			}
		}
	}
	for(int pass=0;pass<olen;pass++){
		for(int c=0;c<olen-1;c++){
			if(odd[c]<odd[c+1]){
				int hold=odd[c];
				odd[c]=odd[c+1];
				odd[c+1]=hold;
			}
		}
	}	
	
	for(int x=0;x<olen;x++){
		printf("%d ",odd[x]);
	}
	for(int y=0;y<elen;y++){
		if(y == elen-1){
			printf("%d",even[elen-1]);
		}
		else{
			printf("%d ",even[y]);
		}
	}
	puts("");
	
return 0;  
}