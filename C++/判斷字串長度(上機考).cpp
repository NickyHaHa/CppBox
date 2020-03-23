#include<iostream>
#include<string.h>
#include<string>
#include<vector>
using namespace std;

int main()
{
	string sen;
	getline(cin , sen);
	char S[sen.size()]; //.c_str
	for(int x=0;x<sen.size();x++){
		S[x] = sen[x];
	}

	vector< char >head;
	vector< int >lon;

	char *token = strtok(S , " ");
	while(token != NULL){
		head.push_back(token[0]);
		lon.push_back(strlen(token));
		token = strtok(NULL, " ");
	}

	int max=0,check=0;
	for(int x=0;x<lon.size();x++){
		if(lon.at(x) > max)max=lon.at(x);
		check = x;
	}
	char ans = head.at(check)-32;    //turn to uppercase
	cout << ans << " " << max << endl;
	/*cout << endl;
	for(int y=0;y<head.size();y++){
		cout << head.at(y) << " ";
	}
	cout << endl;
	for(int z=0;z<lon.size();z++){
		cout << lon.at(z) << " ";
	}*/
}