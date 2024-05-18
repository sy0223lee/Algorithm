#include <iostream>
using namespace std;

int main(){
    int N; // 찾을 문자열의 길이 = 2*N+1
    int M; // 입력 문자열 길이
    string S; // 입력 문자열
    int ans = 0; // P의 개수

    cin >> N >> M >> S;

    // I를 찾은 후 OI의 개수를 세고 N과 일치하는 경우 ans++
    for(int i=0; i<M-2*N; i++){
        if(S[i] == 'I'){
            int cnt = 0;
            while(S[i+1] == 'O' && S[i+2] == 'I'){
                cnt++;
                i += 2; // 마지막으로 찾은 I 위치로 index 변경하기
                if(cnt == N){
                    ans++;
                    cnt--; // 다음에도 OI가 나오면 다음 것도 ans++ 해야하므로 이를 계산하기 위해 cnt--
                }
            }
        }
    }

    cout << ans;  
    
    return 0;
}