#include <iostream>
#include <vector>
#include <queue>
#include <algorithm> // sort, fill

using namespace std;

vector<int> map[1001];
bool visit[1001];
int N, M, V; // 정점의 개수, 간선의 개수, 시작 정점 번호

void DFS(int v){
    visit[v] = true;
    cout << v << " ";

    for(int i : map[v]){
        if(!visit[i])
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

        for(int w : map[v]){
            if(!visit[w]){
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
        map[x].push_back(y);
        map[y].push_back(x);
    }
    for(int i=1; i<=N; i++){
        sort(map[i].begin(), map[i].end());
    }

    DFS(V);
    cout << endl;
    fill(visit, visit + N + 1, false);
    BFS(V);

    return 0;
}