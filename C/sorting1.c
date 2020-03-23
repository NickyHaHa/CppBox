#include <stdio.h>
#define SIZE 3

int main()
{
	int integer[SIZE];
	
	for(int s=0;s<SIZE;s++){	//s=scan times
		scanf("%d",&integer[s]);
	}
	
	for(int pass=1;pass<SIZE;pass++){	//pass=做'排大小'的次數
		for(int c=0;c<SIZE-1;c++){		//c=排大小
		
			if(integer[c]>integer[c+1]){
				int hold=integer[c];
					integer[c]=integer[c+1];
					integer[c+1]=hold;
			}	
		}
	}
	
	for(int p=0;p<SIZE;p++){		//p=print times
		if(p == 9){
			printf("%d", integer[9]);
		}
		else{
			printf("%d ", integer[p]);
		}
	}
	printf("\n");
	
return 0;
}