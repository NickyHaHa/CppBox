#include<iostream>
#include<vector>
using namespace std;

int main()
{
    vector< int >prime;
    vector< int >d;
    size_t num,count=1,a=5;

    cin >> num;
    prime.push_back(2);
    for(size_t start=0;start<=num;start++){         //EX: num=10
        for(size_t x=2;x<=start;x++){               //first get prime = 2
            if(start%x ==0)break;                   //start=3,x=2 ->get 3
            else if(start ==x+1){                   //start=4,x=2 not(because 4%2=0 break)
                prime.push_back(start);
            }
        }
    }

    for(size_t y=0;y<prime.size();y++){
        if(a%5 == 0){
        cout << count << ". ";
        count++;
        }
        if((y+1)%5 ==0){
            cout << prime.at(y) << endl;
            a++;
        }
        else{
            cout << prime.at(y) << " ";
            a++;
        }
    }
    cout << endl;

    cout << count << ". ";
    for(size_t in=2;in<=num;in++){
        while(num%in ==0){
            d.push_back(in);
            num=num/in;
        }
    }
    for(size_t y=0;y<d.size()-1;y++){
        cout << d.at(y) << '*';
    }
    cout << d.back() << endl;
}