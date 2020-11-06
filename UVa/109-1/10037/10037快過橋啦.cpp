#include<bits/stdc++.h>
using namespace std;

int main(){

    int tc;
    scanf("%d", &tc);

    while(tc--){
        int man, sd;
        scanf("%d", &man);

        int po[ man+5 ];
        for(int i = 0; i < man; i++){
            scanf("%d", &sd);
            po[ i ] = sd;
        }

        sort(po, po+man);

        //Case1: every time fastest two man go, then slowest two man go
        //EX: 1 2 5 10, 1 and 2 go then 1 back, 10 and 5 go then 2 back
        //Case2: every time fastest with slowest
        //EX: 1 2 5 10, 1 and 10 go then 1 back, 1 and 5 go then 1 back 
        
        //man >= 4
        int i, time = 0;
        for(i = man-1; i >= 3; i -= 2)
        {
            int cs1 = po[1] + po[0] + po[i] + po[1];
            int cs2 = po[i] + po[0] + po[i-1] + po[0];
            time += min(cs1, cs2);
        }

        //man = 3, 2, 1
        //1 2 3->1 2, 1, 1 3
        if(i == 2)time += (po[1] + po[0] + po[2]);
        else if(i == 1)time += po[1];
        else if(i == 0)time += po[0];

        //Total time spent
        printf("%d\n", time);

        for(i = man-1; i >= 3; i -= 2)
        {
            int cs1 = po[1] + po[0] + po[i] + po[1];
            int cs2 = po[i] + po[0] + po[i-1] + po[0];

            if(cs1 < cs2)
            {   
                //two go one back, two go one back
                printf("%d %d\n", po[0], po[1]);
                printf("%d\n", po[0]);
                printf("%d %d\n", po[i-1], po[i]);
                printf("%d\n", po[1]);
            }
            else
            {
                printf("%d %d\n", po[0], po[i-1]);
                printf("%d\n", po[0]);
                printf("%d %d\n", po[0], po[i]);
                printf("%d\n", po[0]);                
            }
        }

        if(i == 2)
        {
            printf("%d %d\n", po[0], po[1]);
            printf("%d\n", po[0]);
            printf("%d %d\n", po[0], po[2]);
        }
        else if(i == 1)printf("%d %d\n", po[0], po[1]);
        else if(i == 0)printf("%d\n", po[0]);

        if(tc)printf("\n");
    }
}
