#include <iostream>
using namespace std;

int main(){
    int T = 0, N = 0;
    long long dp[101] = {0,};
    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 1;
    dp[4] = 2;
    dp[5] = 2;

    cin >> T;
    for(int i=0; i<T; i++){
        cin >> N;
        for(int j=6; j<=N; j++){
            if(dp[j] == 0){
                dp[j] = dp[j-5] + dp[j-1];
            }
        }
        cout << dp[N] << "\n";
    }
    return 0;
}