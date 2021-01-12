#include<bits/stdc++.h>
using namespace std;

int n, d, bomb[ 1024+5 ][ 1024+5 ];

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        cin >> d >> n;
        memset(bomb, 0, sizeof(bomb));

        int rx, ry, rat;
        for (int i = 0; i < n; i++)
        {
            cin >> rx >> ry >> rat;

            int Leftx = max(0, rx - d);
            int Rightx = min(1024, rx + d);
            int Bottomy = max(0, ry - d);
            int Topy = min(1024, ry + d);

            //根據炸彈延伸範圍加上老鼠數量
            for (int x = Leftx; x <= Rightx; x++)
            {
                for (int y = Bottomy; y <= Topy; y++)
                    bomb[ x ][ y ] += rat;
            }
        }

        //把能炸死最多老鼠的點紀錄
        int ansx, ansy, cnt = 0;
        for (int x = 1024; x >= 0; x--)
        {
            for (int y = 1024; y >= 0; y--)
            {
                if (bomb[ x ][ y ] >= cnt)
                {
                    cnt = bomb[ x ][ y ];
                    ansx = x;
                    ansy = y;
                }
            }
        }

        cout << ansx << " " << ansy << " " << cnt << endl;
    }
}