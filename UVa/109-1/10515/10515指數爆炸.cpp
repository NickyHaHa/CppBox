#include<bits/stdc++.h>
using namespace std;

int main(){

    /*-----
    0>0>0>0
    1>1>1>1
    2>4>8>6
    3>9>7>1
    4>6>4>6
    5>5>5>5
    6>6>6>6
    7>9>3>1
    8>4>2>6
    9>1>9>1
    -----*/

    int moder[ 10 ] = {1, 1, 4, 4, 2, 1, 1, 4, 4, 2};

    //0~9 's power tail number
    int tail[ 10 ][ 4 ] = {
        {0}, {1}, {6, 2, 4, 8}, {1, 3, 9, 7}, {6, 4}, {5},
        {6}, {1, 7, 9, 3}, {6, 8, 4, 2}, {1, 9}
    };

    string n1, n2;
    while(cin >> n1 >> n2)
    {
        if(n1[ 0 ] == '0' && n2[ 0 ] == '0')break;
        else
        {
            if(n2[ 0 ] == '0')
            {
                cout << 1 << endl;
                continue;
            }
            else
            {   
                //EX: n1 = 23, n2 = 99
                //m = 3, n = 0
                //n->9, %moder[3] = 1, n->19, %moder[3] = 3
                long long int m = n1[ n1.length()-1 ] - '0', n = 0;
                for(int i = 0; i < n2.length(); i++)
                {
                    n = n * 10 + n2[ i ] - '0';
                    n = n % moder[ m ];
                }
                
                cout << tail[ m ][ n ] << endl;
            }
        }
    }
}