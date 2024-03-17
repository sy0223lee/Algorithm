#include <iostream>

using namespace std;

int main(){
    int T;
    cin >> T;

    for(int i=0; i<T; i++){
        int H, W, N;
        cin >> H >> W >> N;

        int x = 0; // 호수
        int y = N % H;  // 층수
        if(y == 0){
            // 나머지가 0이면 H층 N/H호
            y = H;
            x = N/H;
        }
        else{
            x = N/H + 1;
        }

        cout << y*100 + x << endl;
    }
    return 0;
}