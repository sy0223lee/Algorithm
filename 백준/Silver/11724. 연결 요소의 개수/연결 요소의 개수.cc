#include <iostream>
#include <queue>

using namespace std;

int main(){
    int N = 0, M = 0;
    int u = 0, v = 0;
    bool map[1001][1001] = {0,};
    bool visited[1001] = {0,};
    queue<int> q;
    int count = 0;

    cin >> N >> M;
    for(int i=0; i<M; i++){
        cin >> u >> v;
        map[u][v] = map[v][u] = true;
    }

    for(int i=1; i<=N; i++){
        if(!visited[i]){
            q.push(i);
            visited[i] = true;
            count++;

            while(!q.empty()){
                u = q.front();
                q.pop();

                for(v=1; v<=N; v++){
                    if(map[u][v] && !visited[v]){
                        q.push(v);
                        visited[v] = true;
                    }
                }
            }
        }
    }

    cout << count << endl;
    
    return 0;
}