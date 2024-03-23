#include <iostream>

using namespace std;

int main(){
    int N = 0, K = 0;
    int count = 0;
    int coin[10] = {0,};
    cin >> N >> K;
    for(int i=0; i<N; i++){
        cin >> coin[i];
    }
    for(int i=N-1; i>=0; i--){
        if(coin[i] <= K){
            count += K / coin[i];
            K %= coin[i];
        }
    }
    cout << count << endl;
    return 0;
}