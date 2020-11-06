#include<bits/stdc++.h>
using namespace std;

int DP[ 1000+5 ][ 1000+5 ];

int main(){

    int tc, cnt = 0;
    string S;

    cin >> tc;
    getchar();
    while(tc--)
    {   
        cnt++;
        getline(cin, S);
        int len = S.length();

        //Bulid the empty table
        for(int i = 0; i < len; i++)DP[ i ][ i ] = 0;

        //Case1: str[i] = str[j], update-> [i+1,j-1]
        //Case2: str[i] != str[j], find the min
        //{[i,j-1], [i+1,j-1], [i+1,j]}+1 <-update
        for(int i = len-1; i >= 0; i--){
            for(int j = i+1; j < len; j++)
            {
                if(S[ i ] == S[ j ])
                    DP[ i ][ j ] = DP[ i+1 ][ j-1 ];
                else DP[ i ][ j ] = min(min(DP[i][j-1], DP[i+1][j-1]), DP[i+1][j])+1;
            }
        }
        printf("Case %d: %d\n", cnt, DP[0][len-1]);
    }
}