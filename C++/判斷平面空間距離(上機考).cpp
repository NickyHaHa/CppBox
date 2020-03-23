#include<iostream>
#include<string.h>
#include<string>
#include<math.h>
#include<stdlib.h>					//for function : atoi

using namespace std;

void distance(int x,int y,int z,int X,int Y,int Z);
void distance(int a,int b,int c,int d);

int main()
{
	//宣告一字串，讀入後將其轉為strtok能夠使用的型態
	string number;
	getline(cin,number);
	char num[number.size()+1];
	for(int x=0;x<number.size()+1;x++){
		num[x]=number[x];
	}

	//利用atoi，把int存入ans陣列裡，再判斷token有個決定平面還是空間
	int ans[(number.size()+1)/2],count =0;
	char *token = strtok(num, " ");
	while(token != NULL){
		for(int x=0;x<(number.size()+1)/2;x++){
			ans[x]=atoi(token);					//atoi(char): let char to become int
			token = strtok(NULL, " ");
			count ++;
		}
	}
	if(count == 4)distance(ans[0],ans[1],ans[2],ans[3]);
	if(count == 6)distance(ans[0],ans[1],ans[2],ans[3],ans[4],ans[5]);

}

void distance(int x,int y,int z,int X,int Y,int Z)
{
	int ans=(x-X)*(x-X)+(y-Y)*(y-Y)+(z-Z)*(z-Z);
	cout << sqrt(ans) << endl;
}

void distance(int a,int b,int c,int d)
{
	int ans=(a-c)*(a-c)+(b-d)*(b-d);
	cout << sqrt(ans) << endl;
}