#include<bits/stdc++.h>
using namespace std;

int main(){
    //freopen("11157.out","w",stdout);
    int T, count = 0;
    cin >> T;

    while(T--){

        count++;
        int N, D;
        cin >> N >> D;

        vector< char >S;
        vector< int >L;
        char stone;
        int M;

        S.push_back('B');
        L.push_back(0);

        for(int x = 0;x < N; x++){

            cin >> stone;
            S.push_back(stone);
            getchar();
            cin >> M;
            L.push_back(M);
        }

        S.push_back('B');
        L.push_back(D);

        vector< char >s;
        vector< int >l;
        s.push_back('B');
        l.push_back(0);

        int step = -1;
        int flag = 0;               //紀錄 S 交錯踩
        int now = 0;                //紀錄目前所踩石頭的距離

        for(int y = 0;y <= N+1; y++){

            if(S[y] == 'B'){

                if(L[y]-now > step)step = L[y]-now;

                now = L[y];
                s.push_back(S[y]);
                l.push_back(L[y]);
            }

            //S 石頭踩一次就沉，故不存進新的 vector 中
            if(S[y] == 'S' && flag == 0){

                if(L[y]-now > step)step = L[y]-now;
                now = L[y];
                flag = 1;
            }

            //連續的 S 石頭，不踩直接存入新 vector 中
            else if(S[y] == 'S' && flag == 1){

                s.push_back(S[y]);
                l.push_back(L[y]);
                flag = 0;
            }
        }

        s.push_back('B');
        l.push_back(D);
        now = D;

        for(int z = s.size()-1; z >= 0; z--){

            if(now - l[z] > step)step = now - l[z];

            now = l[z];
        }

        cout << "Case " << count << ": " << step << endl ;

        S.clear();
        L.clear();
        s.clear();
        l.clear();
    }
}
