#include<bits/stdc++.h>
using namespace std;

//Interval of electricty
//cwh = 2*100, 3*9900, 5*990000
int cwh[ 3 ] = {200, 29700, 4950000};
int range[ 3 ] = {100, 9900, 990000};
int price[ 4 ] = {2, 3, 5, 7};
long long int consume(int x);

int main(){

    //A = me and neighbor total bill
    //B = neighbor bill - my bill
    int A, B;
    while(cin >> A >> B)
    {
        if(A == 0 && B == 0)break;

        //Caculate A that how much cwh used
        //EX: A=35515->A>200,total+100,A-200
        //A=35315->A>29700,total+9900,A-29700
        //A=5615->A/5=1123,total+1123=11123
        int i;
        long long int full = 0;
        for(i = 0; i < 3; i++)
        {
            if(A > cwh[ i ])
            {
                full += range[ i ];
                A -= cwh[ i ];
            }
            else break;
        }
        A /= price[ i ];
        full += A;

        //Use Bisection to find my cwh
        long long int me, nei, L = 0, M, R = full;
        while(L <= R)
        {
            M = (L+R)/2;
            me = consume(M);
            nei = consume(full-M);

            //If neighbor bill - mine = B, that really my bill!
            //Else if my bill > nei's OR nei's - mine < B, then R = M-1
            //Else L = M+1
            if(nei - me == B)
            {
                cout << me << endl;
                break;
            }
            else if(me > nei || nei - me < B)
                R = M - 1;
            else L = M + 1;
        }
    }
}

long long int consume(int x){

    //Give electicity used to find bill to pay
    //EX: x=10123->x>100,cs+200,x-100
    //x=10023->x>9900,cs+29700,x-9900
    //x=123->cs+(123*5)=30515
    int j;
    long long int cs = 0;
    for(j = 0; j < 3; j++)
    {
        if(x > range[ j ])
        {
            cs += cwh[ j ];
            x -= range[ j ];
        }
        else break;
    }

    cs += x * price[ j ];
    return cs;
}
