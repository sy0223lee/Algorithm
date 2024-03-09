#include <iostream>

using namespace std;

int main(){
    int dp[41] = {0, 1,};
    int T, N;

    for(int i=2; i<41; i++){
        dp[i] = dp[i-2] + dp[i-1];
    }

    cin >> T;

    for(int i=0; i<T; i++){
        cin >> N;

        if(N == 0)
            cout << 1 << " " << 0 << "\n";
        else
            cout << dp[N-1] << " " << dp[N] << "\n";
    }
}