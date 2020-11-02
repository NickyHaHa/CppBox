#include<bits/stdc++.h>
using namespace std;

int main(){

    int tc, arr[ 1000+2 ];
    cin >> tc;

    while(tc--){

        int group;
        cin >> group;

        int cut = 2, sum = 0, t;
        for(t = 0; t < group; t++){

            sum += cut;
            if(sum > group)break;
            arr[ t ] = cut;
            cut++;
        }
        //EX: group = 7.    arr[0][1]
        //sum = 9, cut = 4.     2  3
        int left = group - (sum - cut);

        for(int i = t; i >= 0, left+1 > 0; i--){
            //arr[1]++ = 4, arr[0]++ = 2
            arr[ i ]++;
            left--;
            //If plus a round, then go next round
            if(i == 0)i = t;
        }

        cout << arr[ 0 ];
        for(int j = 1; j < t; j++){
            cout << " " << arr[ j ];
        }

        cout << endl;
        if(tc != 0)cout << endl;
    }
}
