#include <iostream>
using namespace std;

int r, c;
int count;

void Z(int x, int y, int size){
    if(x == r && y == c){
        cout << count;
        return;
    }
    if(r < x+size && r >= x && c < y+size && c >= y){
        // 현재 사분면에 있는 경우
        Z(x, y, size/2); // 1사분면
        Z(x, y+size/2, size/2); // 2사분면
        Z(x+size/2, y, size/2); // 3사분면
        Z(x+size/2, y+size/2, size/2); // 4사분면
    }
    else{
        // 현재 사분면에 없는 경우 현재 사분면 모두 방문
        count += size * size;
    }
}

int main(){
    int N = 0;
    cin >> N >> r >> c;
    Z(0, 0, (1 << N)); // shift연산자 이용
    return 0;
}