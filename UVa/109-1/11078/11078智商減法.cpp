#include<bits/stdc++.h>
using namespace std;

int main(){

    int tc;
    scanf("%d", &tc);
    while(tc--){

        int person;
        scanf("%d", &person);

        vector< int >IQ;
        for(int x = 0; x < person; x++){

            int i;
            scanf("%d", &i);
            IQ.push_back(i);
        }

        int ans = IQ[ 0 ] - IQ[ 1 ], maxiq = IQ[ 0 ];
        for(int y = 1; y < IQ.size(); y++){

            //Find the max(L-R), and if find more big L-> update L
            ans = max(ans, maxiq - IQ[ y ]);
            maxiq = max(maxiq, IQ[ y ]);
        }
        printf("%d\n", ans);
    }
}
