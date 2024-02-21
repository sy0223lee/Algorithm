#include <iostream>
#include <queue>

using namespace std;

bool map[102][102];
int dist[102][102];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int N, M;

// 최단거리를 구해야 하므로 BFS가 적절
int BFS(int x, int y){
    queue<pair<int, int>> q;
    q.push(make_pair(x, y));
    dist[x][y] = 1;

    while(!q.empty()){
        x = q.front().first;
        y = q.front().second;
        q.pop();

        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 1 || nx > N || ny < 1 || ny > M)
                continue;
            if(map[nx][ny] && !dist[nx][ny]){
                dist[nx][ny] = dist[x][y] + 1;
                q.push(make_pair(nx, ny));
            }
        }
    }

    return dist[N][M];
}

int main(){    
    string str;

    cin >> N >> M;
    for(int i=1; i<=N; i++){
        cin >> str;
        for(int j=1; j<=M; j++){
            map[i][j] = str[j-1] - '0'; // char형을 int형으로 변환
        }
    }

    cout << BFS(1, 1);

    return 0;
}