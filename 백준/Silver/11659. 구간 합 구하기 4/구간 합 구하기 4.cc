#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios::sync_with_stdio(false); // 시간 초과 해결
    cin.tie(NULL);
	cout.tie(NULL);

    int N = 0, M = 0;
    int i = 0, j = 0;
    vector<int> dp;
    dp.push_back(0);
    
    cin >> N >> M;
    for(int x=1; x<=N; x++){
        int num; cin >> num;
        dp.push_back(num + dp[x-1]);
    }
    for(int x=0; x<M; x++){
        cin >> i >> j;
        cout << dp[j] - dp[i-1] << "\n";
    }
}