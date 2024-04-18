#include <iostream>
using namespace std;

int N, M;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int map[500][500];
bool visited[500][500];
int answer;

void DFS(int x, int y, int cnt, int sum){
    if(cnt == 4){
        answer = max(sum, answer);
        return;
    }
    for(int i=0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx < 0 || nx >= N || ny < 0 || ny >= M)
            continue;
        if(!visited[nx][ny]){
            visited[nx][ny] = true;
            DFS(nx, ny, cnt + 1, sum + map[nx][ny]);
            visited[nx][ny] = false;
        }
    }
    // ㅗ,ㅜ,ㅏ,ㅓ 모양은 DFS로 확인 불가능    
    if(x-1 >= 0 && y-1 >= 0 && x+1 < N) { //ㅓ
        answer = max(answer, (map[x-1][y] + map[x][y-1] + map[x][y] + map[x+1][y]));
    }
    if(x-1 >= 0 && y+1 < M && x+1 < N) { //ㅏ
        answer = max(answer, (map[x-1][y] + map[x][y+1] + map[x][y] + map[x+1][y]));
    }
    if(x-1 >= 0 && y-1 >= 0 && y+1 < M) { //ㅗ
        answer = max(answer, (map[x][y] + map[x-1][y] + map[x][y-1] + map[x][y+1]));
    }
    if(y-1 >= 0 && y+1 < M && x+1 < N) { //ㅜ
        answer = max(answer, (map[x][y-1] + map[x][y] + map[x][y+1] + map[x+1][y]));
    }
}

int main(){
    cin >> N >> M;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> map[i][j];
        }
    }

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            visited[i][j] = true;
            DFS(i, j, 1, map[i][j]);
            visited[i][j] = false;
        }
    }

    cout << answer;

    return 0;
}