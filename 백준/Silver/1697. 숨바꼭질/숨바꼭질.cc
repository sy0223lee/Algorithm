#include <iostream>
#include <queue>

using namespace std;

int main(){
    int visit[100001] = { 0, };
    queue<int> q;
    int N, K;

    cin >> N >> K;

    // BFS
    q.push(N);
    visit[N] = 1;

    while(!q.empty()){
        int v = q.front();
        q.pop();
    
        if(v == K) {
            cout << visit[K] - 1;
            break;
        }

        if(v-1 >= 0 && visit[v-1] == 0){
            q.push(v-1);
            visit[v-1] = visit[v] + 1;
        }
        if(v+1 <= 100000 && visit[v+1] == 0){
            q.push(v+1);
            visit[v+1] = visit[v] + 1;
        }
        if(v*2 <= 100000 && visit[v*2] == 0){
            q.push(v*2);
            visit[v*2] = visit[v] + 1;
        }
    }

    return 0;
}