#include<stdio.h>  

int main()  
{  
	int num;
	scanf("%d",&num);
	int ary[num];
	for(int x=0;x<num;x++){
		scanf("%d",&ary[x]);
	}
	
	for(int pass=0;pass<num;pass++){
		for(int c=0;c<num-1;c++){
			if(ary[c]>ary[c+1]){
				int hold=ary[c];
				ary[c]=ary[c+1];
				ary[c+1]=hold;
			}
		}
	}
	
	for(int x=0;x<num;x++){
		printf("%d ",ary[x]);
	}
	
return 0;  
}