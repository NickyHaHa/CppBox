#include<bits/stdc++.h>
using namespace std;

bitset<45> vis[ 40+5 ][ 40+5 ];
int G[ 40+5 ][ 40+5 ];

void Floyd(int n)
{
    for(int c = 1; c <= n; c++)
    {
        for(int x = 1; x <= n; x++)
        {
            for(int y = 1; y <= n; y++)
                G[ x ][ y ] = min(G[ x ][ y ], G[ x ][ c ] + G[ c ][ y ]);
        }
    }

    for(int c = 1; c <= n; c++)
    {
        for(int x = 1; x <= n; x++)
        {
            for(int y = 1; y <= n; y++)
                if(G[ x ][ y ] == G[ x ][ c ] + G[ c ][ y ])
                    vis[ x ][ y ][ c ] = 1;
        }
    }
}

int main(){

    int n;
    string line;
    while(cin >> n)
    {
        getchar();
        memset(G, 0, sizeof(G));

        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                if(i != j)G[ i ][ j ] = 1e9;
                vis[ i ][ j ].reset();
            }

            //以 stream 方式作為 cin
            getline(cin, line);
            stringstream sin(line);
            int num;
            while(sin >> num)G[ i ][ num ] = 1;
        }

        //先將所有輸入的點連好
        Floyd(n);

        //測試資料輸入
        int tc, num;
        vector<int>ck;
        bitset<45>ans;

        cin >> tc;
        getchar();
        while(tc--)
        {   
            ck.clear();
            ans.reset();

            getline(cin, line);
            stringstream sin(line);
            while(sin >> num)ck.push_back(num);

            for(int i = 0; i < ck.size(); i++)
                for(int j = i+1; j < ck.size(); j++)
                    ans |= vis[ ck[i] ][ ck[j] ];

            if(ans.count() == n)cout << "yes" << endl;
            else cout << "no" << endl;
        }
    }
}
