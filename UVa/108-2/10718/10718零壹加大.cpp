#include<bits/stdc++.h>
using namespace std;

int main(){

    long long N, L, U;
    while(cin >> N >> L >> U){

        long long M = 0;
        for(int x = 31; x >= 0; x--){

            long long sll = (long long)1 << x;  //Shift Left x
            long long tmp = (M | sll);

            if((N & sll) == 0){                 //N bit 位元 = 0 時
                if(M+sll <= U)M = tmp;          //M bit 設 1後不大於上限，可以!
            }

            else{                               // = 1 時
                if(M+sll-1 < L)M = tmp;         //M bit 設 0 = M + 2^位元-1
            }
        }

        cout << M << endl;
    }
}
