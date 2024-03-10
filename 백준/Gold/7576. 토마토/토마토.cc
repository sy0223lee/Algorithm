#include <iostream>
#include <queue>

using namespace std;

// 크기가 큰 배열은 지역 변수로 선언하면 chkstk_ms 에러 발생
int storage[1001][1001] = {0,}; // 창고
int dx[4] = {1,0,-1,0}; // x좌표 이동 방향
int dy[4] = {0,1,0,-1}; // y좌표 이동 방향

int main(){
    int M, N;   // 가로, 세로
    int day = 0; // 날짜
    bool isRipe = 1; // 모든 토마토가 익은 경우
    queue<pair<int, int>> q;  // bfs를 위한 queue

    // storage 초기화
    cin >> M >> N;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> storage[i][j];
            if(storage[i][j] == 0){
                isRipe = false;
            }else if(storage[i][j] == 1){
                q.push(make_pair(i, j));
            }
        }
    }

    // BFS
    if(isRipe){ // 저장 때부터 모든 토마토가 익은 경우
        cout << 0 << endl;
    }else{
        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            
            for(int i=0; i<4; i++){
                int nx = x + dx[i];
                int ny = y + dy[i];

                if(nx < 0 || nx >= N || ny < 0 || ny >= M){
                    continue;
                }

                if(storage[nx][ny] == 0){
                    q.push(make_pair(nx, ny));
                    storage[nx][ny] = storage[x][y] + 1;
                }
            }
        }

        // 모든 토마토가 익었는지 확인
        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++){
                if(storage[i][j] == 0){
                    cout << -1 << endl;
                    return 0;
                }
                if(day < storage[i][j]){
                    day = storage[i][j];
                }
            }
        }
        cout << day - 1 << endl;
    }

    return 0;
}