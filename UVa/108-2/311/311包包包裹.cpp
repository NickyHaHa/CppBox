#include<bits/stdc++.h>
using namespace std;

int main(){

    //freopen("311.out","w",stdout);
    int pa[10] = { 0 };
    //int siz[6] = {1, 4, 9, 16, 25, 36};
    int one[5] = {0, 7, 6, 5};          //在6x6的箱子中放 i(i > 0) 個3x3箱子，剩餘1x1空間的數量
    int two[5] = {0, 5, 3, 1};          //剩餘2x2空間的數量

    while(1){

        int count = 0;
        for(int x = 1; x <= 6; x++){

            cin >> pa[ x ];
            if(pa[ x ] == 0)count++;
        }

        if(count == 6)break;
        else{

            int ans = pa[6] + pa[5] + pa[4] + (pa[3]+3)/4;  //6x6、5x5、4x4、3x3的所需包裹數
            int left_2 = 0, left_1 = 0;                     //剩餘2x2、1x1空間數

            left_1 += pa[ 5 ]*11 + one[ pa[3] % 4 ];        //剩餘1x1空間數
            left_2 += pa[ 4 ]*5 + two[ pa[3] % 4 ];         //剩餘2x2空間數

            if(left_2 < pa[ 2 ]){                           //如果原2x2包裹數多於2x2剩餘空間數

                int left = pa[ 2 ] - left_2;
                int temp = (left + 8)/9;
                ans +=  temp;
                left_1 += 4*(9*temp - left);
            }
            else left_1 += 4*(left_2 - pa[ 2 ]);

            if(left_1 < pa[ 1 ])ans += (pa[1] - left_1 + 35)/36;

            cout << ans << endl;
        }

    }

}
