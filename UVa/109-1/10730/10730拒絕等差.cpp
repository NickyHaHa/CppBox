#include<bits/stdc++.h>
using namespace std;

int main(){

    int ele;
    while(cin >> ele)
    {
        if(ele == 0)break;
        //讀入 ':'
        char t;
        cin >> t;

        int E[ 10000+5 ];
        for(int i = 0; i < ele; i++)
        {
            int x;
            cin >> x;
            E[ x ] = i;
        }

        bool have = 0;

        //等差從 1 開始向上跑，視 index 為值
        for(int i = 1; i < ele; i++)
        {
            for(int j = 0; j + 2*i < ele; j++)
            {
                //判斷數列遞增 or 遞減
                if((E[ j ] < E[ j+i ] && E[ j+i ] < E[ j+2*i ]) || (E [ j ] > E [j+i ] && E[ j+i ] > E[ j+2*i ]))
                    have = 1;
            }
        }

        if(have)cout << "no" << endl;
        else cout << "yes" << endl;
    }
}
