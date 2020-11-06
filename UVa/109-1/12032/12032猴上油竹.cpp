#include<bits/stdc++.h>
using namespace std;

int main(){

    int tc, count = 0;
    cin >> tc;
    while(tc--){

        count++;
        int k;
        vector< int >rung;
        cin >> k;

        rung.push_back(0);
        for(int i = 0; i < k; i++){
            int r;
            cin >> r;
            rung.push_back(r);
        }

        //From top to end to build strength
        int str = 0;
        for(int j = rung.size()-1; j >= 1; j--){
            if(str < rung[ j ] - rung[ j-1 ])
                str = rung[ j ] - rung[ j-1 ];
            //If is from end to top, it will make strength--
            //However now is reverse, so ++
            else if(str == rung[ j ] - rung[ j-1 ])str++;
        }
        cout << "Case " << count << ": " << str << endl;
    }
}
