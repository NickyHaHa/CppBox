#include<bits/stdc++.h>
using namespace std;

int main(){

    int tc;
    cin >> tc;
    while(tc--){

        int n, t, m;
        cin >> n >> t >> m;
        int car[ 1500 ];

        for(int x = 0; x < m ; x++)
            cin >> car[ x ];

        int trip = 0, time = 0;

        //Case 1:只需運送一趟
        if(m <= n){
            cout << car[m-1]+t << " " << 1 << endl;
        }

        else{

            //Case 2:每趟都載滿，只需m/n趟
            if(m%n == 0){

                int tmp = n;
                while(tmp <= m){

                    time = max(car[ tmp-1 ], time);
                    time += 2*t;
                    tmp += n;
                }
                trip = m/n;

                cout << time-t << " " << trip << endl;
            }

            //Case 3:除了第一趟未載滿，其他趟都載滿
            else{

                int left = m % n;
                time = car[ left-1 ] + 2*t;
                int tmp = n + left;
                while(tmp <= m){

                    time = max(car[ tmp-1 ], time);
                    time += 2*t;
                    tmp += n;
                }
                trip = m/n + 1;

                cout << time-t << " " << trip << endl;
            }
        }
    }
}
