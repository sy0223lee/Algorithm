#include <iostream>
#include <queue>
using namespace std;

int main(){
    int N, M;
    int map[101] = {0,}; // 사다리, 뱀이 없으면 0
    bool visited[101] = {0,};
    queue<pair<int, int>> q; // 현재 위치, 주사위 던진 횟수

    cin >> N >> M;
    for(int i=0; i<N; i++){ // 사다리
        int x, y;
        cin >> x >> y;
        map[x] = y;
    }
    for(int i=0; i<M; i++){ // 뱀
        int u, v;
        cin >> u >> v;
        map[u] = v;
    }

    q.push({1,0});
    while(!q.empty()){
        int cur = q.front().first;
        int cnt = q.front().second;
        q.pop();

        for(int i=1; i<=6; i++){
            int next = cur + i;
            if(next == 100){
                cout << cnt+1;
                return 0;
            }else if(next > 100){
                continue;
            }
            while(map[next] != 0){ // 뱀과 사다리가 없을 때까지 이동
                next = map[next];
            }
            if(!visited[next]){ // 방문하지 않은 칸이면
                q.push({next, cnt + 1});
                visited[next] = true;
            }
        }
    }
    return 0;
}