#include<bits/stdc++.h>
using namespace std;

int N, xi[20000+5], ci[100000+5], di[100000+5];
long long int BIT[100000+5];
void add(int x);
long long int query(int x);

int main(){
    
    int tc;
    cin >> tc;
    while(tc--)
    {
        cin >> N;
        for(int i = 0; i < N; i++)
        {
            int r;
            cin >> r;
            xi[ i ] = r;
        }

        //From top to end, scan number to build BIT tree and ci[]
        //rank[0]=8, ci[8]++
        memset(BIT, 0, sizeof(BIT));
        for(int i = 0; i < N; i++)
        {
            ci[ i ] = query(xi[i]);
            add(xi[ i ]);
        }

        //From end to top, do the same like ci[]
        memset(BIT, 0, sizeof(BIT));
        for(int i = N - 1; i >= 0; i--)
        {
            di[ i ] = query(xi[i]);
            add(xi[ i ]);
        }

        //Formula: c*(N-i-1-d)+(i-c)*d
        //左小*右大 + 左大*右小
        long long int ans = 0;
        for(int i = 0; i < N; i++)
        {
            long long int L = ci[i]*(N-i-1-di[i]);
            long long int R = di[i]*(i-ci[i]);
            ans += L+R;
        }

        cout << ans << endl;
    }
}

int lowbit(int x){
    return x & (-x);
} 

void add(int x){

    while(x <= 100005){
        BIT[ x ]++;
        x += lowbit(x);
    }
}

long long int query(int x){

    long long int sum = 0;
    while(x > 0){
        sum += BIT[ x ];
        x -= lowbit(x);
    }

    return sum;
}
