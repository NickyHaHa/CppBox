#include<iostream>
#include<vector>

using namespace std;

int main()
{
	//input 10 numbers into vector 			EX: 2 2 3 3 4 4 5 7 7 9
	vector< int >N;					// adress : 0 1 2 3 4 5 6 7 8 9
	int num;
	for(int x=0;x<10;x++){			//最後一個-倒數第二個不等於0、1時，代表中間必有缺項
		cin >> num;					//9-7=2 ->for迴圈產生9-1=8
		N.push_back(num);
	}

	//sort the vector
	for(int y=0;y<10;y++){
		for(int z=0;z<10-1;z++){
			if(N.at(z) > N.at(z+1)){
				int hold=N.at(z);
				N.at(z)=N.at(z+1);
				N.at(z+1)=hold;
			}
		}
	}

	//confirm the number that it doesn't exist in vector N
	vector< int >O;
	int ans;
	for(int w=9;w>0;w--){
		if(N.at(w)-N.at(w-1) != 0 && N.at(w)-N.at(w-1) != 1){
			ans=N.at(w)-N.at(w-1);
			for(int v=1;v<ans;v++){
				O.push_back(N.at(w)-v);
			}
		}
	}

	//output them
	for(int u=O.size()-1;u>=0;u--){
		cout << O.at(u) << " ";
	}
}