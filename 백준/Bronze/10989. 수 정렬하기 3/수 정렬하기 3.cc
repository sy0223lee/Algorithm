#include <iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(false); // cin, cout으로 인한 시간초과 해결
    int N = 0;
    int num = 0;
    int count[10001] = {0,};

    cin >> N;
    for(int i=0; i<N; i++){
        cin >> num;
        count[num]++;
    }

    for(int i=1; i<10001; i++){
        for(int j=0; j<count[i]; j++){
            cout << i << "\n";
        }
    }
    return 0;
}