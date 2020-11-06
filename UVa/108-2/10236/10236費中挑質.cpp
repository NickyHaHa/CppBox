#include<bits/stdc++.h>
using namespace std;

const int maxnum = 250000;
const int maxprime = 25000;

int FP[ maxprime ];
bool vis[ maxnum ];

int main(){

    long long x = 0, y = 1, tmp, i, j;
    int count;
    for (count = 1, i = 2; count < maxprime; i++){

        tmp = x+y;
        x = y;
        y = tmp;

        if(y >= 1e10){
            y /= 10;
            x /= 10;
        }

        if(!vis[i]){
            tmp = y;
            while(tmp >= 1e9){
                tmp /= 10;
            }

            FP[count++] = tmp;

            for(j = i*i; j < maxnum; j += i){
                vis[j] = true;
            }
        }
    }

    FP[ 1 ] = 2;
    FP[ 2 ] = 3;

    int n;
    while(cin >> n){
        cout << FP[ n ] << endl;
    }
}
