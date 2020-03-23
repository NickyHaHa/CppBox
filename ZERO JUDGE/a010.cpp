#include<iostream>
using namespace std;

int main(){

	int num, count = 2, sum = 0;
	while(cin >> num){
		count = 2;
		while(num != 1){
			sum = 0;
			if(num % count == 0){
				sum++;
				num = num / count;
				while(num % count == 0){
					sum++;
					num = num / count;
				}
				if(sum > 1 && num == 1)cout << count << "^" << sum;
				if(sum > 1 && num != 1)cout << count << "^" << sum << " * ";
				if(sum == 1 && num != 1)cout << count << " * ";
				if(sum == 1 && num == 1)cout << count;
			}
			count++;
		}
		cout << endl;
	}
}