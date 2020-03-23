#include<stdio.h>    
    
int main()    
{    
    int num,ans=0;    
    scanf("%d", &num);    
    char N[num][num];    
     
    for(int x=0;x<num;x++){    
        for(int y=0;y<num;y++){    
            scanf(" %c",&N[x][y]);    
        }    
    }    
  
    //start brute force    
    for(int z=0;z<num;z++){    
        if(N[z][0]=='Q'){    
            for(int w=1;w<num;w++){    
                if(N[z][w]=='Q'){    
                    ans=-1;  
                }    
            }    
        }    
            
        if(N[z][1]=='Q'){    
            for(int w=0 && w!=1;w<num;w++){    
                if(N[z][w]=='Q'){    
                    ans=-1;    
                }                           
            }    
        }    
            
        if(N[z][2]=='Q'){    
            for(int w=0 && w!=2;w<num;w++){    
                if(N[z][w]=='Q'){    
                    ans=-1;    
                }                           
            }    
        }           
    
        if(N[z][3]=='Q'){    
            for(int w=0 && w!=3;w<num;w++){    
                if(N[z][w]=='Q'){    
                    ans=-1;    
                }                           
            }    
        }           
    
        if(N[z][4]=='Q'){    
            for(int w=0 && w!=4;w<num;w++){    
                if(N[z][w]=='Q'){    
                    ans=-1;    
                }                           
            }    
        }           
    
        if(N[z][5]=='Q'){    
            for(int w=0 && w!=5;w<num;w++){    
                if(N[z][w]=='Q'){    
                    ans=-1;    
                }                           
            }    
        }    
                
    
        if(N[z][6]=='Q'){    
            for(int w=0 && w!=6;w<num;w++){    
                if(N[z][w]=='Q'){    
                    ans=-1;    
                }                           
            }    
        }    
            
    
        if(N[z][7]=='Q'){    
            for(int w=0;w<num-1;w++){    
                if(N[z][w]=='Q'){    
                    ans=-1;    
                }                           
            }    
        }    
    }       
      
        
    if(ans==-1){    
        printf("Yes\n");    
    }    
        else{    
            printf("No\n");    
        }    
    
return 0;    
    
}