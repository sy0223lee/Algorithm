#include <iostream>
#include <queue>
using namespace std;

int N, M;
int lab[8][8];
int tmp[8][8];
int safeArea;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void copyArray(int a[8][8], int b[8][8]){
    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            a[i][j] = b[i][j];
        }
    }
}

void spreadVirus(){
    int spread[8][8] = {0,};
    copyArray(spread, tmp); // tmp는 buildWall에서 다시 사용해야 하므로 값이 변경되면 X

    queue<pair<int, int>> q;
    // 바이러스가 있는 칸들 queue에 push
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(spread[i][j] == 2){
                q.push({i, j});
            }
        }
    }
    // BFS
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 0 || nx >= N || ny < 0 || ny >= M)
                continue;
            if(spread[nx][ny] == 0){
                spread[nx][ny] = 2;
                q.push({nx, ny});
            }
        }
    }
    // 안전영역 개수 세기
    int cnt = 0;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(spread[i][j] == 0){
                cnt++;
            }
        }
    }
    safeArea = max(safeArea, cnt);
}

void buildWall(int wallCnt){
    if(wallCnt == 3){ // 벽 3개를 다 세운 경우 바이러스 퍼뜨리기
        spreadVirus();
        return;
    }
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(tmp[i][j] == 0){
                tmp[i][j] = 1;
                buildWall(wallCnt + 1);
                tmp[i][j] = 0;
            }
        }
    }
}

int main(){
    // 시간초과 해결
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> lab[i][j];
        }
    }
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(lab[i][j] == 0){
                copyArray(tmp, lab);
                tmp[i][j] = 1;
                buildWall(1);
            }
        }
    }    

    cout << safeArea;

   return 0;
}