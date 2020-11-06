#include<bits/stdc++.h>
using namespace std;

double t1, t2, s1, s2, width, height;
double getA(double w){

    double leftY, rightY, topX, downX;
    leftY = t1 + w;
    rightY = t2 + w;
    topX = s2 - w;
    downX = s1 - w;

    //是否在矩形各邊上
    bool isL = leftY <= s2 && leftY >= s1;
    bool isR = rightY <= s2 && rightY >= s1;
    bool isT = topX <= t2 && topX >= t1;
    bool isD = downX <= t2 && downX >= t1;

    //Case 1: 線切矩形於左、右邊
    if(isL && isR)
        return ((s2 - leftY) + (s2 - rightY)) * width / 2;
    //Case 2: 線切矩形於左、上邊
    if(isL && isT)
        return (s2 - leftY) * (topX - t1) / 2;
    //Case 3: 線切矩形於下、上邊
    if(isD && isT)
        return ((downX - t1) + (topX - t1)) * height / 2;
    //Case 4: 線切矩形於下、右邊
    if(isD && isR)
        return width * height - ((t2 - downX) * (rightY - s1) / 2);
    //Case 5: 矩形在線上方or下方
    return leftY <= s1 ? width * height : 0;
}

int main(){

    int tc, count = 1;
    cin >> tc;
    while(tc--){

        double w;
        cin >> t1 >> t2 >> s1 >> s2 >> w;
        width = t2 - t1;
        height = s2 - s1;

        //總面積 = -w 與 +w 之間相減
        double Area1 = getA(w);
        double Area2 = getA(-w);
        double ans = (Area2 - Area1) / (width * height);
        printf("Case #%d: %6lf\n", count, ans);
        count++;
    }
}
