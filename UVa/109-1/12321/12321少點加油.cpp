#include<bits/stdc++.h>
using namespace std;

int main(){

    int L, G;
    while(cin >> L >> G)
    {
        if(L == 0 && G == 0)break;

        pair<int, int>gas[G];

        //Store the left-end and right-end in pair
        for(int x = 0; x < G; x++)
        {
            int xi, ri;
            cin >> xi >> ri;
            gas[x] = make_pair(xi-ri, xi+ri);
        }

        sort(gas, gas+G);

        //Find the min place to cover 0~L
        int left = 0, right = 0, c = 0, del = 0;
        while(left < L)
        {   
            //Check if left-end > left number, update left number
            //else-> check right-end whether > right number and update
            while(c < G && gas[c].first <= left)
            {
                if(gas[c].second > right)
                    right = gas[c].second;
                c++;
            }

            if(left == right)break;

            left = right;
            del++;
        }

        //Have ans: right num >= L OR left num = right num >= L
        //No solution: left = right but right < L
        if(left < L)cout << -1 << endl;

        //del is best ans to cover 0~L, so must let G sub del
        else cout << G - del << endl;
    }
}