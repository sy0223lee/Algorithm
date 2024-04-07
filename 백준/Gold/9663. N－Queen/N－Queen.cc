#include <iostream>
#include <vector>
using namespace std;

int N;
int count = 0;
vector<int> visited(15, -1); // visited[3] = 4 => 3행 4열에 배치
// 한 행에 하나밖에 배치할 수 없으므로 1차원 배열로 표현 가능

bool isAble(int curQ){
    // 가로: 판단할 필요 X
    // 세로: 현재 배치한 퀸의 열 != 배치했던 퀸의 열
    // 대각선: 현재 배치한 퀸의 행 - 배치했던 퀸의 행 != |현재 배치한 퀸의 열 - 배치했던 퀸의 열|
    for (int i = 0; i < curQ; i++){
        if (visited[curQ] == visited[i] || curQ - i == abs(visited[curQ] - visited[i])) // 배치 불가능한 조건
            return 0;
    }
    return 1; // 배치 가능
}

void SetQueen(int curQ){
    if (curQ == N){
        count++;
        return;
    }
    for (int j = 0; j < N; j++){
        visited[curQ] = j; // curQ행 j열에 배치
        if (isAble(curQ))
            SetQueen(curQ + 1); // 다음 행 배치 확인
    }
}

int main(){
    cin >> N;
    SetQueen(0);
    cout << count;
}