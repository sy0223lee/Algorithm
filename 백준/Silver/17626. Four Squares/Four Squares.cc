#include <iostream>
using namespace std;

int dp[50001];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    // dp[i] = dp[j*j] + dp[i - j*j]
    // dp[j*j] = 1
    // dp[i] = dp[i - j*j] + 1
    for(int i=1; i<=n; i++){
        dp[i] = dp[i-1] + 1;
        for(int j=1; j*j<=i; j++){
            dp[i] = min(dp[i], dp[i - j*j] + 1);
        }
    }

    cout << dp[n];

    return 0;
}