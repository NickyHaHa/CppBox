#include<bits/stdc++.h>
using namespace std;

int find_node(int x);
int node[ 20000+5 ];
int ds[ 20000+5 ];

int main(){


    int tc;
    cin >> tc;
    while(tc--){

        int N;
        cin >> N;

        for(int i = 1; i <= N; i++){
            node[ i ] = i;
            ds[ i ] = 0;
        }

        char op;
        while(cin >> op){

            if(op == 'O')break;
            else{

                int a, b;
                if(op == 'E'){
                    cin >> a;
                    find_node(a);
                    cout << ds[ a ] << endl;
                }

                else if(op == 'I'){
                    int u, v;
                    cin >> u >> v;
                    node[ u ] = v;              //Union : node u's farther is node v
                    ds[ u ] = abs(u - v)%1000;
                }
            }
        }
    }
}

int find_node(int x){

    if(node[ x ] != x){                         //If node x not a center

        int root = find_node(node[ x ]);        //Ex : [1] [2] [3] [4]
        ds[ x ] += ds[ node[ x ] ];             //      1   3   4   1
        return node[ x ] = root;                //node[2] != 2 -> find node[3] -> find node[4]
    }                                           //find node[1] == 1, done!
    else return x;
}
