#include<bits/stdc++.h>
using namespace std;

int prime[ 3000000 ];
int binary(int n)
{
    int L = 0, R = 3000000, M;
    while(L <= R)
    {
        M = (L + R) / 2;

        if(n == prime[M])return M;

        else if(n < prime[ M ])R = M-1;

        else L = M+1;
    }

    return -1;
}

void primeTable()
{
    //建階層質因數表並過篩
    for(int i = 0; i < 3000000; i++)prime[i] = 1;
    prime[0] = 0;
    prime[1] = 0;

    for(int i = 2; i < 3000000; i++)
    {
        if(prime[i])
        {
            for(int j = 2; j*i < 3000000; j++)
            {
                prime[ i*j ] = prime[ i ] + prime[ j ];
            }
        }
    }

    //prefix sum
    for(int i = 2; i < 3000000; i++)
        prime[ i ] += prime[ i-1 ];
}

int main(){

    primeTable();

    int num, cnt = 0;
    while(cin >> num)
    {
        cnt++;
        if(num < 0)break;
        else if(num == 0)cout << "Case " << cnt << ": 0!" << endl;
        else if(num == 1)cout << "Case " << cnt << ": 2!" << endl;
        else
        {
            cout << "Case " << cnt << ": ";

            int check = binary(num);
            if(check > 0)cout << check << "!" << endl;
            else cout << "Not possible." << endl;
        }
    }
}

