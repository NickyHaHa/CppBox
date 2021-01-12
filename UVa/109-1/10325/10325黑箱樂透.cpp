#include<bits/stdc++.h>
using namespace std;

// long long gcd(long long a, long long b)
// {
//     return b ? gcd(b, a%b) : a;
// }
long long lcm(long long a, long long b)
{
    return a * b / __gcd(a, b);
}

int main()
{
    int N, M;
    while(cin >> N >> M)
    {
        vector<int>num;
        for(int i = 0; i < M; i++)
        {
            int n;
            cin >> n;
            num.push_back(n);
        }

        // 奇數集合 做 +
        // 偶數集合 做 -
        // 檢查 1 ~ (2^M)-1 去生成集合的位元, EX:
        // A B C
        // 0 0 1 = C集合，奇數，LCM = (1,C), +(N/LCM)
        // 0 1 1 = B交C，偶數，LCM = (B,C), -(N/LCM)

        long long nowLCM;
        int oneCNT, sum = 0;
        for(int i = 1; i < (1 << M); i++)
        {
            nowLCM = 1;
            oneCNT = 0;
            for(int j = 0; j < M; j++)
            {
                if(i & (1 << j))
                {
                    nowLCM = lcm(nowLCM, num[ j ]);
                    oneCNT++;
                }
                if(nowLCM > N)break;
            }

            if(nowLCM > N)continue;

            if(oneCNT % 2)sum += N / nowLCM;
            else sum -= N / nowLCM;
        }

        cout << N - sum << endl;
    }
}
