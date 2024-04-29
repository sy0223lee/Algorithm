#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(){
    vector<int> map[101];
    int N, M, a, b;
    int sum = 5000, result = 0;

    cin >> N >> M;
    for(int i=0; i<M; i++){
        cin >> a >> b;
        map[a].push_back(b);
        map[b].push_back(a);
    }

    for(int i=1; i<=N; i++){
        queue<int> q;
        bool visited[N+1] = {0,};
        int count[N+1] = {0,};
        // BFS
        q.push(i);
        visited[i] = true;
        while(!q.empty()){
            a = q.front();
            q.pop();

            for(b=0; b<map[a].size(); b++){
                if(!visited[map[a][b]]){
                    q.push(map[a][b]);
                    visited[map[a][b]] = true;
                    count[map[a][b]] = count[a] + 1;
                }
            }
        }
        // 케빈 베이컨 계산
        int tmp = 0;
        for(a=1; a<=N; a++){
            tmp += count[a];
        }
        if(tmp < sum){
            sum = tmp;
            result = i;
        }
    }
    
    cout << result;
    return 0;
}