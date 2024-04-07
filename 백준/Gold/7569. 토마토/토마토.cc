#include <iostream>
#include <queue>
using namespace std;

int box[101][101][101]; // [H][N][M]
int dh[6] = {1, 0, 0, -1, 0, 0};
int dn[6] = {0, 1, 0, 0, -1, 0};
int dm[6] = {0, 0, 1, 0, 0, -1};
struct point{
    int h;
    int n;
    int m;
};

int main(){
    int M, N, H;
    int day = 0;
    bool isRipe = 1; // 모든 토마토가 익은 경우
    queue<point> q;
    cin >> M >> N >> H;
    for(int i=0; i<H; i++){
        for(int j=0; j<N; j++){
            for(int k=0; k<M; k++){
                cin >> box[i][j][k];
                if(box[i][j][k] == 0){
                    isRipe = false;
                }else if(box[i][j][k] == 1){
                    q.push({i, j, k});
                }
            }
        }
    }
    // 익은 토마토들만 들어온 경우
    if(isRipe){
        cout << day;
        return 0;
    }
    // BFS
    while(!q.empty()){
        int h = q.front().h;
        int n = q.front().n;
        int m = q.front().m;
        q.pop();

        for(int i=0; i<6; i++){
            int nh = h + dh[i];
            int nn = n + dn[i];
            int nm = m + dm[i];

            if(nh < 0 || nh >= H || nn < 0 || nn >= N || nm < 0 || nm >= M){
                continue;
            }

            if(box[nh][nn][nm] == 0){
                q.push({nh, nn, nm});
                box[nh][nn][nm] = box[h][n][m] + 1;
            }
        }
    }
    // 모든 토마토가 익었는지 확인
    for(int i=0; i<H; i++){
        for(int j=0; j<N; j++){
            for(int k=0; k<M; k++){
                if(box[i][j][k] == 0){
                    cout << -1 << endl;
                    return 0;
                }
                if(day < box[i][j][k]){
                    day = box[i][j][k];
                }
            }
        }
    }
    cout << day - 1 << endl;
    
    return 0;
}