#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    for(int t=0; t<T; t++){        
        int N;
        int ans = 8; // 8은 나올 수 있는 최대 심리적 거리
        int cnt;
        vector<string> mbti;

        cin >> N;
        mbti.resize(N);
        for(int i=0; i<N; i++){
            cin >> mbti[i];
        }

        if(N > 32){
            cout << "0\n";
            continue;
        }

        for(int i=0; i<N-2; i++){
            for(int j=i+1; j<N-1; j++){
                for(int k=j+1; k<N; k++){
                    cnt = 0;
                    for(int m=0; m<4; m++){
                        if(mbti[i][m] != mbti[j][m]) cnt++;
                        if(mbti[j][m] != mbti[k][m]) cnt++;
                        if(mbti[k][m] != mbti[i][m]) cnt++;
                    }
                    if(ans > cnt) ans = cnt;
                }
            }
        }

        cout << ans << "\n";
    }
    return 0;
}