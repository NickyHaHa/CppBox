#include<iostream>
#include<string>
using namespace std;

class animal{
	public:
		int pig;
		int cow;
		int sheep;
		int chicken;	
};	
		void pignumber(int x){
				cout << "The most animal is pig have " << x << "." << endl;
		}
		void cownumber(int y){
				cout << "The most animal is cow have " << y << "." << endl;
		}
		void chickennumber(int z){
				cout << "The most animal is chicken have " << z << "." << endl;
		}			
			
int main()
{
	animal count;
	count.pig=0;
	count.cow=0;
	count.chicken=0;
	count.sheep=0;
	
	unsigned int kind,num;
	string ani;	
	
	if((cin >> kind) && kind==0)cout << "The most animal is NULL have 0." << endl;	
	else{	
		for(size_t u=0;u<kind;u++){
			cin >> ani >> num;
			if(ani =="pig")count.pig+=num;
				
			if(ani =="cow")count.cow+=num;
							
			if(ani =="chicken")count.chicken+=num;				
			
			if(ani =="sheep")count.sheep+=num;									
		}
	}
	
	if(count.pig>count.cow && count.pig>count.chicken){
		pignumber(count.pig);
	}
	if(count.cow>count.pig && count.cow>count.chicken){
		cownumber(count.cow);
	}	
	if(count.chicken>count.cow && count.chicken>count.pig){
		chickennumber(count.chicken);
	}
}