#include<bits/stdc++.h>
using namespace std;

bool can;
long N, M;

//dfs
void jump_check(long step, long rock)
{
    if(rock == M)
    {
        can = true;
        return;
    }

    if(rock > N || rock < 1)return;

    step++;
    jump_check(step, rock + 2*step-1);
    jump_check(step, rock - 2*step+1);
}

int main(){

    while(cin >> N >> M)
    {
        if(N == 0 && M == 0)break;

        if(N >= 49)cout << "Let me try!" << endl;

        else{
            can = false;
            jump_check(1, 1);
            if(can)cout << "Let me try!" << endl;
            else cout << "Don't make fun of me!" << endl;
        }
    }
}