#include <iostream>
using namespace std;

int main(){
    int M;  // 전체 무게
    int count = -1; // 봉지 개수

    cin >> M;

    for(int i = M/5; i >= 0; i--){
        int leftM = M - 5*i;    // 남은 무게

        if(leftM % 3 == 0){
            count += (i + leftM / 3) + 1;
            break;
        }
    }
    
    cout << count;

    return 0;
}