#include <iostream>
#include <queue>
#include <string.h> // memset

using namespace std;

bool map[1001][1001];
bool visit[1001];
int N, M, V; // 정점의 개수, 간선의 개수, 시작 정점 번호

void DFS(int v){
    visit[v] = true;
    cout << v << " ";

    for(int i = 1; i <= N; i++){
        if(map[v][i] && !visit[i])
            DFS(i);
    }
}

void BFS(int v){
    queue<int> q;
    q.push(v);
    visit[v] = true;    

    while(!q.empty()){
        v = q.front();
        cout << v << " ";
        q.pop();

        for(int w = 1; w <= N; w++){
            if(map[v][w] && !visit[w]){
                q.push(w);
                visit[w] = true;
            }
        }
    }
}

int main(){
    cin >> N >> M >> V;

    for(int i=0; i<M; i++){
        int x, y;
        cin >> x >> y;
        map[x][y] = map[y][x] = 1;
    }

    DFS(V);
    cout << endl;
    memset(visit, false, sizeof(visit));
    BFS(V);

    return 0;
}