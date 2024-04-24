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
    
    // 작아지기
    int sub = N;
    while(sub >= 0){
        string tmp = to_string(sub);
        for(int i=0; i<tmp.length(); i++){
            if(errBtn[tmp[i] - 48]){
                sub--;
                flag = false;
                break;
            }
        }
        if(flag){
            cnt = tmp.length() + N - sub;
            ans = min(ans, cnt);
            break;
        }else{
            flag = true;
        }
    }
    // 커지기
    int add = N;
    while(add <= 1000000){
        string tmp = to_string(add);
        for(int i=0; i<tmp.length(); i++){
            if(errBtn[tmp[i] - 48]){
                add++;
                flag = false;
                break;
            }
        }
        if(flag){
            cnt = tmp.length() + add - N;
            ans = min(ans, cnt);
            break;
        }else{
            flag = true;
        }
    }

    cout << ans;

    return 0;
}