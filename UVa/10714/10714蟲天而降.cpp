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

        int ear = 0, lat = 0;
        for(int y = 0; y < A.size(); y++){

            if(A[y] <= L/2){
                ear = max(ear, A[y]);
                lat = max(lat, L - A[y]);
            }

            else{
                ear = max(ear, L - A[y]);
                lat = max(lat, A[y]);
            }
        }

        cout << ear << " " << lat << endl;
        A.clear();
    }
}
