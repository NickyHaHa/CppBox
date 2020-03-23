#include<iostream>
#include<math.h>
#include<string>
using namespace std;

int main(){

	string eng;
	while(getline(cin, eng)){
		for(int x = 0;x < eng.size();x++){
			eng[x] = eng[x] - 7;
			cout << eng[x];
		}
		cout << endl;
	}
}