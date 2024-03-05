#include <iostream>
#include <vector>

using namespace std;

bool farm[51][51];
bool visit[51][51];;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void DFS(int x, int y){
    if(!visit[x][y])
        visit[x][y] = true;
    else
        return;
    
    for(int i=0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx > 50 || nx < 0 || ny > 50 || ny < 0)
            break;
        
        if(farm[nx][ny] && !visit[nx][ny]){
            DFS(nx, ny);
        }
    }
}

int main(){
    int T; // 테스트 케이스 개수
    cin >> T;
    
    for(int i=0; i<T; i++){
        int M, N; // 배추밭의 가로, 세로
        int K; // 배추가 심어진 위치의 개수]
        int cnt = 0; // 필요한 지렁이 수
        cin >> M >> N >> K;

        for(int j=0; j<K; j++){
            int X, Y; // 배추의 위치
            cin >> X >> Y;

            farm[X][Y] = true;
        }

        for(int j=0; j<M; j++){
            for(int k=0; k<N; k++){
                if(farm[j][k] && !visit[j][k]){
                    DFS(j, k);
                    cnt++;
                }
            }
        }

        cout << cnt << endl;
        for(int j=0; j<M; j++){
            fill_n(farm[j], N, false);
            fill_n(visit[j], N, false);
        }
    }    
    
    return 0;
}