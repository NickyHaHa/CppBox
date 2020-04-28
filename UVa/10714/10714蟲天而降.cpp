#include<bits/stdc++.h>
using namespace std;

int main(){
    //freopen("test.out","w",stdout);
    int test;
    cin >> test;
    while(test--){

        int L, ant;
        cin >> L >> ant;

        vector< int >A;
        for(int x = 0; x < ant; x++){

            int dis;
            cin >> dis;
            A.push_back(dis);
        }

        int ear = 0, lat = 0;               //最快掉光與最慢掉光
        for(int y = 0; y < A.size(); y++){

            if(A[y] <= L/2){                //檢查左中前的點
                ear = max(ear, A[y]);       //最早 = 離左端點最遠的值
                lat = max(lat, L - A[y]);   //最晚 = (離右端點-目前位置的值)的最大值
            }

            else{                           //右後的點
                ear = max(ear, L - A[y]);   //最早 = (離右端點-目前位置的值)的最大值
                lat = max(lat, A[y]);       //最晚 = 離左端點最遠的值
            }
        }

        cout << ear << " " << lat << endl;
        A.clear();
    }
}
