#include <iostream>
#include <queue>

using namespace std;

int main(){
    int N; // 총 컴퓨터 수
    int M; // 연결된 컴퓨터 쌍
    int x, y; // 컴퓨터 번호
    int cnt = 0; // 감염된 컴퓨터 수
    bool com[101][101] = {0,};
    bool isVisit[101] = {0,};

    cin >> N >> M;
    for(int i=0; i<M; i++){
        cin >> x >> y;
        com[x][y] = com[y][x] = true;
    }

    isVisit[1] = true;
    for(int i=2; i<=N; i++){
        if(com[1][i] && !isVisit[i]){  // BFS
            queue<int> q;
            q.push(i);
            isVisit[i] = true;
            cnt++;

            while(!q.empty()){
                x = q.front();
                q.pop();

                for(int j=2; j<=N; j++){
                    if(com[x][j] && !isVisit[j]){
                        q.push(j);
                        isVisit[j] = true;
                        cnt++;
                    }
                }
            }
        }
    }

    cout << cnt << endl;

    return 0;
}