#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M, count;
vector<string> map;
bool visited[601][601];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

void BFS(int x, int y){
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[x][y] = true;

    while(!q.empty()){
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        for(int i=0; i<4; i++){
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if(nx < 0 || nx >= N || ny < 0 || ny >= M){
                continue;
            }
            if(map[nx][ny] != 'X' && !visited[nx][ny]){
                if(map[nx][ny] == 'P'){
                    count++;
                }
                visited[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }
}

int main(){
    int x, y;
    cin >> N >> M;

    for(int i=0; i<N; i++){
        string tmp;
        cin >> tmp;
        map.push_back(tmp);
        for(int j=0; j<M; j++){
            if(tmp[j] == 'I'){
                x = i; y = j;
            }
        }
    }

    BFS(x, y);
    if(count == 0){
        cout << "TT";
    }else{
        cout << count;
    }

    return 0;
}