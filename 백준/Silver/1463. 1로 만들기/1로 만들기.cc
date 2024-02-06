#include <iostream>
#include <queue>

using namespace std;

int visit[1000001];

void BFS(int n){
    queue<int> q;
    q.push(n);
    visit[n] = 1;

    while(!q.empty()){
        int cur = q.front();
        q.pop();

        if(cur < 1) break;

        // 3으로 나누어 떨어지고 아직 방문 X
        if(cur%3 == 0 && visit[cur/3] == 0){
            q.push(cur/3);
            visit[cur/3] = visit[cur] + 1;
        }
        // 2로 나누어 떨어지고 아직 방문 X
        if(cur%2 == 0 && visit[cur/2] == 0){
            q.push(cur/2);
            visit[cur/2] = visit[cur] + 1;
        }
        // -1 아직 방문 X
        if(visit[cur-1] == 0){
            q.push(cur-1);
            visit[cur-1] = visit[cur] + 1;
        }
    }
}

int main(){
    int N;
    cin >> N;
    BFS(N);
    cout << visit[1] - 1;

    return 0;
}