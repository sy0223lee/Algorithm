#include <iostream>
using namespace std;

int dp[101][100001];
int W[101];
int V[101];

int main(){
    int N, K;
    cin >> N >> K;
    for(int i=1; i<=N; i++){
        cin >> W[i] >> V[i];
    }

    for(int i=1; i<=K; i++){ // 최대무게가 1일 때부터 K일 때까지
        for(int j=1; j<=N; j++){ // j번째 물건
            if(W[j] > i){ // j번째 물건의 무게가 최대무게 i보다 크면
                dp[j][i] = dp[j-1][i];
            }else{ // j번째 물건의 무게가 최대무게보다 작거나 같으면
                dp[j][i] = max(dp[j-1][i-W[j]] + V[j], dp[j-1][i]);
                // '최대무게가 K-W[j]일 때 이전 물건까지 고려한 최대 가치 + j번째 물건의 가치'와
                // '이전 물건까지 고려한 최대 가치' 중 큰 값을 배열에 저장
            }
        }
    }

    cout << dp[N][K];
    
    return 0;
}