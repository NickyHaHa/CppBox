#include<stdio.h>    //查詢
#include<string.h>

struct student{
    char id[7];
    char name[7];
    char ans[21];
    double score;
};

int main()
{
    FILE *F;
    struct student dt={"","","",0.0}; //初始化!!
    char stdid[7];
    char stdname[7];
    char correct[21];
    int test=0;
	
    printf("%s","Enter student's ID : \n"); 
    F = fopen("DataV1.txt", "rt");
    
    fscanf(F,"%6s%6s%20s",stdid,stdname,correct);
    
    char ID[7];
    scanf("%s",ID);
    while(fscanf(F,"%6s%6s%20s",dt.id,dt.name,dt.ans) !=EOF){
        if(strcmp(ID,dt.id) == 0){
            printf("\nThe standard data is : \n%s %s %20s\n",stdid,stdname,correct);
            printf("\nThe student's data is : \n%s %s %20s\n",dt.id,dt.name,dt.ans);
            
            for(size_t s=0;s<20;s++){
                if(correct[s] == dt.ans[s])dt.score=dt.score+5;
                else if(correct[s] != dt.ans[s] && dt.ans[s] != '*')dt.score=dt.score-1.25;
            }
            if(dt.score <0)printf("\nThis student's score is : 0.000\n");
            printf("\nThis student's score is : %.3f\n",dt.score);
        }          
		else if(strcmp(ID,dt.id) != 0)test++;
    }  
	if(test >=3703)printf("%s","\nCan't find the student .\n");
    fclose(F);
    
return 0;
}