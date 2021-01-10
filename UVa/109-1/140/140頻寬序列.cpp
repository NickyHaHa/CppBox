#include<bits/stdc++.h>
using namespace std;

int main(){

    string tc;
    while(1)
    {
        cin >> tc;
        if(tc[0] == '#')break;

        bool flags[ 26 ];
        int G[ 26 ][ 26 ];
        memset(G, 0, sizeof(G));
        for(int i = 0; i < 26; i++)flags[ i ] = false;

        bool check = false;
        int now = 0;
        //將字母轉成數字紀錄節點是否出現
        for(int i = 0; i < tc.length(); i++)
        {
            if(tc[i] >= 'A' && tc[i] <= 'Z')
                flags[ tc[i] - 'A' ] = true;

            else if(tc[i] == ':')
            {
                now = tc[i-1] - 'A';
                check = true;
            }

            if(check && tc[i] >= 'A' && tc[i] <= 'Z')
                G[ now ][ tc[i]-'A' ] = G[ tc[i]-'A' ][ now ]= 1;

            else if(tc[i] == ';')check = false;
        }

        int tmp[ 10 ], t = 0;
        for(int i = 0; i < 26; i++)
            if(flags[ i ])tmp[ t++ ] = i;

        int ans[ 10 ], pruning_min = 9;

        do{
            int t_min = 0;
            for(int i = 0; i < t; i++)
            {
                for(int j = i+1; j < t; j++)
                {
                    if(G[ tmp[i] ][ tmp[j] ])
                        t_min = max(t_min, abs(i-j));
                }

                if(t_min >= pruning_min)break;
            }

            if(t_min < pruning_min)
            {
                pruning_min = t_min;
                memcpy(ans, tmp, sizeof(tmp));
            }
        }while(next_permutation(tmp, tmp+t));

        for(int i = 0; i < t; i++)
        {
            char out = ans[ i ] + 'A';
            cout << out << " ";
        }
        cout << "-> " << pruning_min << endl;
    }
}