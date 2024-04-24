#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int N; // 이동할 채널
    int M; // 고장난 번호 개수
    bool errBtn[11] = {0,}; // 고장난 번호 = 1
    int num, cnt, ans = 0;
    bool flag = true; // 해당 번호 누르기 가능

    cin >> N >> M;
    for(int i=0; i<M; i++){
        cin >> num;
        errBtn[num] = true;
    }

    if(N == 100){
        cout << 0;
        return 0;
    }
    
    ans = abs(N - 100);
    
    for(int i=0; i<=1000000; i++){
        int flag = true;
        string tmp = to_string(i);
        for(int j=0; j<tmp.length(); j++){
            if(errBtn[tmp[j] - '0']){
                flag = false;
                break;
            }
        }
        if(flag){
            cnt = tmp.length() + abs(N - i);
            ans = min(ans, cnt);
        }
    }

    cout << ans;

    return 0;
}