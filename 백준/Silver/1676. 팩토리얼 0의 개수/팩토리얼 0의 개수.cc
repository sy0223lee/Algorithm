#include <iostream>
using namespace std;

int main(){
    int N = 0;
    int answer = 0;
    cin >> N;
    
    while(N/5 > 0){
        N /= 5;
        answer += N;
    }
    cout << answer;

    return 0;
}