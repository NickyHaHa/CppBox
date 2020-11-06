#include<bits/stdc++.h>
using namespace std;

struct node
{
    double X, Y;
};

//給 sort 用的比較法，return 小 < 大，小到大，反之大到小
int cmp(node A, node B){

    if(A.Y != B.Y)return A.Y < B.Y;
    else return A.X < B.X;
}

node radar[ 1001 ];

int main(){

    //freopen("1193.out","w",stdout);
    int n, d, count = 1;

    while(cin >> n >> d){

        if(n == 0 && d == 0)break;

        int x, y, out = 0;
        for(int a = 0; a < n; a++){

            cin >> x >> y;
            if(abs(y) > d)out = 1;                  //超出可偵測的範圍

            double dis = sqrt(double(d*d - y*y));
            radar[ a ].X = x - dis;                 //左端點
            radar[ a ].Y = x + dis;                 //右端點
        }

        if(out == 1)cout << "Case " << count << ": " << -1 << endl;
        else{

            sort(radar, radar+n, cmp);              //從 radar 頭 ~ radar 尾排序
            int ans = 0;
            double station = -2147483647;

            for(int b = 0; b < n; b++){

                if(radar[ b ].X > station){         //左端點 > 設站點，設新的!

                    station = radar[ b ].Y;         //新的端點 = 右端點
                    ans++;
                }
                else continue;                      //否則跳掉繼續找下一個
            }

            cout << "Case " << count << ": " << ans << endl;
        }

        count++;
    }
}