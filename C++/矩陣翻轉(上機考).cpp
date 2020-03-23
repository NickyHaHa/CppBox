#include<iostream>

using namespace std;

int main()
{
	//claim array size
	int change,size;
	cin >> change >> size;
	int ary[size][size];

	//input array's contents
	for(int x=0;x<size;x++){
		for(int y=0;y<size;y++){
			cin >> ary[x][y];
		}
	}

	//->90.
	if(change == 1){
		int next[size][size]={0};
		for(int a=0;a<size;a++){
			for(int b=0;b<size;b++){
				next[a][b]=ary[size-b-1][a];
			}
		}

		cout << endl;
		for(int x=0;x<size;x++){
			for(int y=0;y<size;y++){
				cout << next[x][y] << " ";
			}
			cout << endl;
		}
	}
	//90.<-
	if(change == 2){
		int next[size][size]={0};
		for(int a=0;a<size;a++){
			for(int b=0;b<size;b++){
				next[a][b]=ary[b][size-a-1];
			}
		}

		cout << endl;
		for(int x=0;x<size;x++){
			for(int y=0;y<size;y++){
				cout << next[x][y] << " ";
			}
			cout << endl;
		}
	}
	//水平翻轉
	if(change == 3){
		int next[size][size]={0};
		for(int a=0;a<size;a++){
			for(int b=0;b<size;b++){
				next[a][b]=ary[size-a-1][b];
			}
		}

		cout << endl;
		for(int x=0;x<size;x++){
			for(int y=0;y<size;y++){
				cout << next[x][y] << " ";
			}
			cout << endl;
		}
	}
	//垂直翻轉
	if(change == 4){
		int next[size][size]={0};
		for(int a=0;a<size;a++){
			for(int b=0;b<size;b++){
				next[a][b]=ary[a][size-b-1];
			}
		}

		cout << endl;
		for(int x=0;x<size;x++){
			for(int y=0;y<size;y++){
				cout << next[x][y] << " ";
			}
			cout << endl;
		}
	}
}