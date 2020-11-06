#include<bits/stdc++.h>
using namespace std;

int main(){

    stack<long long>MAX;
    stack<long long>MIN;
    int tc;
    cin >> tc;
    while(tc--){

        //stack clear
        while(!MAX.empty())MAX.pop();
        while(!MIN.empty())MIN.pop();

        long long num;
        cin >> num;
        MAX.push(num);
        MIN.push(num);

        char op;
        while(scanf("%c", &op) && op != '\n'){

            cin >> num;

            //MAX = 先算+
            if(op == '+'){

                long long tmp = MAX.top();
                MAX.pop();
                tmp += num;
                MAX.push(tmp);

                MIN.push(num);
            }

            //MIN = 先算*
            if(op == '*'){

                long long tmp = MIN.top();
                MIN.pop();
                tmp *= num;
                MIN.push(tmp);

                MAX.push(num);
            }
        }

        long long sumMax = 1, sumMin = 0;
        while(!MAX.empty()){
            sumMax *= MAX.top();
            MAX.pop();
        }
        while(!MIN.empty()){
            sumMin += MIN.top();
            MIN.pop();
        }

        cout << "The maximum and minimum are " << sumMax << " and " << sumMin << "." << endl;
    }

}
