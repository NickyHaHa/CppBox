#include<bits/stdc++.h>
using namespace std;

long long SG(long long x);

int main(){

    int tc;
    scanf("%d", &tc);

    while(tc--)
    {
        int N;
        cin >> N;

        long long ans = 0, tmp;
        for(int i = 0; i < N; i++)
        {
            cin >> tmp;
            ans ^= SG(tmp);
        }

        if(ans)printf("YES\n");
        else printf("NO\n");
    }
}

long long SG(long long x){

    if(x & 1)return SG(x/2);
    else return x/2;
}