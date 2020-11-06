#include<bits/stdc++.h>
using namespace std;

int main(){

    int test;
    cin >> test;

    while(test--){

        vector< int >C;

        int coin;
        cin >> coin;
        int cs;

        for(int x = 0; x < coin; x++){

            cin >> cs;
            C.push_back(cs);
        }

        int sum = C[0];
        int count = 0;

        for(int x = 1; x < C.size()-1; x++){

            if(sum+C[x] < C[x+1]){		//如果總和加目前項 < 下一項，代表目前項能被換到

                count++;
                sum = sum + C[x];		//總和改為與目前項的和，再與下一項比對
            }
        }

        cout << count+2 << endl;	//頭跟尾一定可以被換到，故+2
        C.clear();
    }
}

