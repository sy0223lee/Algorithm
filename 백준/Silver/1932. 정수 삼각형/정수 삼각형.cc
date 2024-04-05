#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n = 0, val = 0;
    vector<vector<int>> dp;
    cin >> n;

    cin >> val;
    dp.push_back({val});
    for(int i=1; i<n; i++){
        vector<int> tmp;
        for(int j=0; j<=i; j++){            
            cin >> val;
            if(j == 0){
                val += dp[i-1][0];
            }else if(j == i){
                val += dp[i-1][j-1];
            }else{
                val += max(dp[i-1][j-1], dp[i-1][j]);
            }
            tmp.push_back(val);
        }
        dp.push_back(tmp);
    }

    val = *max_element(dp[n-1].begin(), dp[n-1].end());
    cout << val;
    
    return 0;
}