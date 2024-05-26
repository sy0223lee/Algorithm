#include <iostream>
using namespace std;

int dp[30][30];

int combination(int m, int n){
    if(n == 0 || m == n){
        return 1;
    }
    if(m <= 0 || n < 0){
        return 0;
    }
    if(dp[m][n] != 0){
        return dp[m][n];
    }
    dp[m][n] = combination(m-1, n-1) + combination(m-1, n);
    return dp[m][n];
}

int main(){
    int T, N, M;
    cin >> T;
    for(int t=0; t<T; t++){
        cin >> N >> M;
        cout << combination(M, N) << '\n';
    }
    
    return 0;
}