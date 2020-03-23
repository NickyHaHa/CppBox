#include<iostream>  
#include<string>  
#include<stdio.h>
using namespace std;  
  
class Animal{  
    public:  
        explicit Animal(){ }  
        int year;  
        int kg;  
        int cost;     
};  
class Elephant: public Animal{  
    public:  
        string name,sex;  
        void set(string N,string S,int Y,int K,int C){  
            name=N;  
            sex=S;  
            year=Y;  
            kg=K;  
            cost=C;       
        }  
        void output(string N,string S,int Y,int K,int C){                
            cout << "name: " << N << endl;  
            cout << "year: " << Y << endl;  
            cout << "weight: " << K << endl;    
            cout << "gender: " << S << endl;  
            cout << "cost: " << C << endl;  
            cout << endl;  
        }  
};  
  
int main()  
{  
    Animal an;  
    Elephant el;  
    string N,S;  
    int test=0,Y=0,K=0,C=0,total=0;  
    cin >> test;  
	
	for(int x=0;x<test;x++){
		cin >> N;
		scanf("%dy %dkg",&Y,&K);
		cin >> S;
		scanf(" %*c%d",&C);
		el.set(N,S,Y,K,C);
		el.output(N,S,Y,K,C);	
		total=total+C;
	}
    cout << "total cost:" << total << endl;  
}