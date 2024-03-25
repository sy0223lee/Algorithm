#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int N = 0;
    int point[301] = {0,};
    int dp[301] = {0,};

    cin >> N;
    for(int i=0; i<N; i++){
        cin >> point[i];
    }
    dp[0] = point[0];
    dp[1] = point[0] + point[1];
    dp[2] = max(point[0] + point[2], point[1] + point[2]);
    for(int i=3; i<N; i++){
        dp[i] = max(dp[i-3] + point[i-1] + point[i], dp[i-2] + point[i]);
    }
    cout << dp[N-1];

    return 0;
}