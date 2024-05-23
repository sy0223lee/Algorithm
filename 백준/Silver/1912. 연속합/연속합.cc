#include <iostream>
using namespace std;

int arr[100001];
int dp[100001];

int main(){
    int n;
    int ans = 0;

    cin >> n;
    cin >> arr[0];
    dp[0] = arr[0];
    ans = dp[0];

    for(int i=1; i<n; i++){
        cin >> arr[i];
        dp[i] = max(dp[i-1] + arr[i], max(arr[i-1] + arr[i], arr[i]));
        ans = max(ans, dp[i]);
    }
    cout << ans;

    return 0;
}