#include<bits/stdc++.h>
using namespace std;

int cnt, k, money;
const int maxn = 1000+1;	//1000個 Component

map<string, int>id;			//紀錄不同種的 Component

int checktype(string s){	//標示第幾種 Component

	if(!id.count(s)){

		id[ s ] = cnt;
		cnt++;
	}

	return id[ s ];
}

struct component
{
	int cost;
	int quality;
};

vector< component >com[ maxn ];

bool ok(int Q);

int main(){

	//freopen("12124.out","w",stdout);
	int T;
	cin >> T;
	while(T--){

		cin >> k >> money;
		cnt = 0;
		//初始化
		for(int x = 0; x < k; x++)com[ x ].clear();
		id.clear();

		int maxQ = 0;
		for(int y = 0; y < k; y++){

			char type[ 30 ], name[ 30 ];
			int c, q;
			cin >> type >> name >> c >> q;
			maxQ = max(maxQ, q);
			com[checktype(type)].push_back((component) {c, q});	//把 Component 資料存入
		}

		//二分法
		int L = 0, R = maxQ;
		while(L < R){

			int mid = L + (R-L+1)/2;
			if(ok(mid))L = mid;
			else R = mid-1;
		}

		cout << L << endl;
	}
}

bool ok(int mid){

	int sum = 0;
	for(int x = 0; x < cnt; x++){

		int cheap = money+1, m = com[ x ].size();
		for(int y = 0; y < m; y++){

			if(com[ x ][ y ].quality >= mid)cheap = min(cheap, com[ x ][ y ].cost);
		}

		if(cheap == money+1)return false;

		sum += cheap;

		if(sum > money)return false;
	}

	return true;
}