#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int num;
	char x;
	vector< int >N;

	while(cin >> x){
		if(x == 'k' || x == 'K')break;
		cin >> num;
		if(x == 'i' || x == 'I')N.push_back(num);
		if(x == 'd' || x == 'D'){
			for(int a=0;a<N.size();a++){
				if(N.at(a) == num){
					N.erase(N.begin()+a);
				}
			}
		}
	}

	for(size_t pass=1; pass < N.size() ;pass++){
		for(size_t count=0; count < N.size()-1 ;count++){
			if(N.at(count)>N.at(count+1)){
				int hold=N.at(count);
				N.at(count)=N.at(count+1);
				N.at(count+1)=hold;
			}
		}
	}

	for(int a=0;a<N.size();a++){
		cout << N.at(a) << endl;
	}
}