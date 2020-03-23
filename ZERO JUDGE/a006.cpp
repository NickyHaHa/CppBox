#include<iostream>
#include<math.h>
using namespace std;

int main(){

	int a, b, c;
	while(cin >> a >> b >> c){
		int num = b*b - 4*a*c;
		if(num > 0){
			cout << "Two different roots x1=" << (-b + sqrt(num))/(2*a) << " , x2=" << (-b - sqrt(num))/(2*a) << endl;
		}
		else if(num == 0){
			cout << "Two same roots x=" << -b/(2*a) << endl;
		}
		else{
			cout << "No real root" << endl;
		}
	}
}