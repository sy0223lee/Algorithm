#include <iostream>

using namespace std;

int main(){
    int T = 0;
    int k = 0, n = 0;
    int dp[15][15] = {0,};
    for(int i=1; i<15; i++){    // dp 초기화
        dp[0][i] = i;
    }

    cin >> T;
    for(int i=0; i<T; i++){
        cin >> k >> n;
        for(int x=1; x<=k; x++){
            for(int y=1; y<=n; y++){
                dp[x][y] = dp[x-1][y] + dp[x][y-1];
            }
        }
        cout << dp[k][n] << "\n";
    }
    return 0;
}