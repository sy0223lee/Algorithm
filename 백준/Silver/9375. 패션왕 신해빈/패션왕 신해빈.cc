#include <iostream>
#include <map>
using namespace std;

int main(){
    int tc;
    int n;
    cin >> tc;
    for(int t=0; t < tc; t++){
        map<string, int> type;
        int ans = 1;
        cin >> n;
        for(int i=0; i<n; i++){
            string tmp;
            cin >> tmp >> tmp;
            type[tmp]++;
        }
        // iterator를 이용해서 for문 돌기
        for(auto iter = type.begin(); iter != type.end(); iter++){
            ans *= (iter -> second + 1);
        }
        cout << ans-1 << '\n';
    }
    return 0;
}