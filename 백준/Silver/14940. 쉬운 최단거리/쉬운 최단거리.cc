#include <iostream>
#include <queue>
using namespace std;

int map[1000][1000] = {0,};
bool visited[1000][1000] = {0,};

int main(){
    int n, m;
    queue<pair<int, int>> q;    
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};

    cin >> n >> m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> map[i][j];
            if(map[i][j] == 2){
                map[i][j] = 0;
                visited[i][j] = true;
                q.push({i, j});                
            }
        }
    }

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 0 || nx >= n || ny < 0 || ny >= m){
                continue;
            }
            if(map[nx][ny] == 1 && !visited[nx][ny]){
                map[nx][ny] = map[x][y] + 1;
                visited[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(map[i][j] == 1 && !visited[i][j]){
                map[i][j] = -1;
            }
            cout << map[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}