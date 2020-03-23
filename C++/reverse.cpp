#include<iostream>
#include<string.h>
#include<string>
using namespace std;

void re(char *NOW,char *NEXT);

int main()
{
	string A,B;
	getline(cin,A);

	char a[A.size()+1],b[A.size()+1];
	for(int x=0;x<A.size()+1;x++){
		a[x]=A[x];
	}
	strcpy(b,a);
	re(a,b);
}

void re(char *NOW,char *NEXT){
	int count=0,x;
	while(*NOW != '\0'){
		count++;
		NOW++;
	}

	NOW--;
	for(x=count;x>0;x--){
		cout << *NOW;
		NOW--;
	}
	cout << endl;

	for(x=0;x<count;x++){
		cout << *NEXT;
		NEXT++;
	}
}