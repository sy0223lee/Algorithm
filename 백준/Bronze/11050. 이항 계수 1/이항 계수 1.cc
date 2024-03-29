#include <iostream>
using namespace std;

int main(){
    int dp[11] = {1,};
    int N = 0, K = 0;
    cin >> N >> K;
    for(int i=1; i<=N; i++){
        dp[i] = dp[i-1]*i;
    }
    cout << dp[N]/dp[N-K]/dp[K] << endl;
    return 0;
}