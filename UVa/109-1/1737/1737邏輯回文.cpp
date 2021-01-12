#include<bits/stdc++.h>
using namespace std;

string abc = "abc";
string acb = "acb";
string bac = "bac";
string bca = "bca";
string cab = "cab";
string cba = "cba";

int main()
{
    int tc;
    cin >> tc;

    if(tc == 1)
    {
        cout << "a" << endl;
        cout << "b" << endl;
        cout << "c" << endl;
    }

    else if(tc == 2)
    {
        cout << "ab" << endl;
        cout << "ac" << endl;
        cout << "ba" << endl;
        cout << "bc" << endl;
        cout << "ca" << endl;
        cout << "cb" << endl;
    }

    else
    {
        int left = tc % 3;
        string one, two, thr, fou, fiv, six;
        for(int i = 0; i < tc/3; i++)
        {
            one += abc;
            two += acb;
            thr += bac;
            fou += bca;
            fiv += cab;
            six += cba;
        }
        for(int j = 0; j < left; j++)
        {
            one += abc[j];
            two += acb[j];
            thr += bac[j];
            fou += bca[j];
            fiv += cab[j];
            six += cba[j];
        }

        if(tc * 6 > 100000)cout << "TOO LONG" << endl;
        else
        {
            cout << one << endl;
            cout << two << endl;
            cout << thr << endl;
            cout << fou << endl;
            cout << fiv << endl;
            cout << six << endl;
        }
    }
}
