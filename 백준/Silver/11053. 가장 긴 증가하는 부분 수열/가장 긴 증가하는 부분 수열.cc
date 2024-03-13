#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int N;
    vector<int> A;  // 수열 A, 숫자들의 순서가 고정되어 있음
    int dp[1001] = {0,};

    cin >> N;
    for(int i=0; i<N; i++){
        int num;
        cin >> num;
        A.push_back(num);
    }
    
    for(int i = 0; i < N; i++){
        dp[i] = 1;
    }

    for(int i = 1; i < N; i++){
        for(int j = i; j >= 0; j--){
            if(A[j] < A[i]){
                if(dp[j] >= dp[i])
                    dp[i] = dp[j] + 1;
            }
        }
    }

    int max = 0;
    for(int i=0; i<N; i++){
        if(max < dp[i])
            max = dp[i];
    }

    cout << max << endl;

    return 0;
}