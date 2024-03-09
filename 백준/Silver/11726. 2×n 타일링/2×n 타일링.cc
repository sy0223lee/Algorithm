#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n;  // 2*n 크기의 직사각형
    vector<int> dp;
    /* 개수가 너무 많아서 long long으로도 감당 X
        따라서 10007로 계속 나눠주면서 더해야 함 */

    cin >> n;
    dp.push_back(1);
    dp.push_back(2);
    
    for(int i=2; i<n; i++){
        dp.push_back((dp[i-1] + dp[i-2]) % 10007);
    }
    
    cout << dp[n-1] << endl;

    return 0;
}
