#include<bits/stdc++.h>
using namespace std;

int main(){

    long long N, L, U;
    while(cin >> N >> L >> U){

        long long M = 0;
        for(int x = 31; x >= 0; x--){

            long long sll = (long long)1 << x;  //Shift Left x
            long long tmp = (M | sll);

            if((N & sll) == 0){                 //N bit �줸 = 0 ��
                if(M+sll <= U)M = tmp;          //M bit �] 1�ᤣ�j��W���A�i�H!
            }

            else{                               // = 1 ��
                if(M+sll-1 < L)M = tmp;         //M bit �] 0 = M + 2^�줸-1
            }
        }

        cout << M << endl;
    }
}
