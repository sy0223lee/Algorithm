#include <iostream>

using namespace std;

int main(){
    long A, B, V;
    int day = 1;
    cin >> A >> B >> V;

    // while문 시간초과 발생

    // 올라가야 하는 높이가 올라갈 수 있는 높이보다
    // 작거나 같으면 하루만에 올라갈 수 있음
    if(A < V){
        // (V-A) / (A-B)
        // 나머지가 생기면 하루 더 올라가야 함
        day += (V-A) / (A-B);
        if((V-A) % (A-B) != 0){
            day++;
        }
    }   
    
    cout << day << endl;

    return 0;
}