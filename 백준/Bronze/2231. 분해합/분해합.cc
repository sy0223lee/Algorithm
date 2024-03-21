#include <iostream>

using namespace std;

int main(){
    int N = 0, M = 0;
    int sub = 0, sum = 0;
    cin >> N;

    for(int i = 1; i < N; i++){
        M = i;
        sub = N - M;
        sum = 0;
        while(M > 0){
            sum += M % 10;
            M /= 10;
        }
        if(sub == sum){
            cout << i << endl;
            return 0;
        }
    }
    cout << 0 << endl;
    return 0;
}