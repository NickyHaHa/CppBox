#include<bits/stdc++.h>
using namespace std;

int bad[ 110 ][ 110 ];
int student, tro;
int vis[ 110 ];
int cls[ 3 ];

int main(){

    int T, count = 0;
    cin >> T;
    for(int x = 0; x < T; x++){

        count++;
        memset(bad, 0, sizeof(bad));
        memset(vis, 0, sizeof(vis));
        memset(cls, 0, sizeof(cls));

        cin >> student >> tro;
        for(int y = 0; y < tro; y++){

            int a, b;
            cin >> a >> b;

            //建立搗蛋鬼的配對
            bad[ a ][ b ] = 1;
            bad[ b ][ a ] = 1;
        }

        int num = 0;
        for(int i = 1; i <= student; i++){

            int tmp1 = 0, tmp2 = 0;
            for(int j = 1; j <= student; j++){

                //如果教室中出現一對，則++
                if(vis[j] == 1 && bad[i][j])tmp1++;
                if(vis[j] == 2 && bad[i][j])tmp2++;
            }

            //小孩加入兩間教室，哪間教室對數較多，小孩就不要放那
            if(tmp1 > tmp2){

                vis[i] = 2;
                cls[ 2 ]++;
                num += tmp2;
            }

            else{

                vis[i] = 1;
                cls[ 1 ]++;
                num += tmp1;
            }
        }

        //至少減到原本對數一半以下
        if(num <= (tro/2)){

            printf("Case #%d: %d\n", count, cls[1]);
            for(int x = 1; x <= student; x++){
                if(vis[ x ] == 1)cout << x << " ";
            }
            cout << endl;
        }

        else printf("Case #%d: Impossible.\n\n", count);
    }

}
