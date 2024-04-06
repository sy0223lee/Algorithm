#include <iostream>
#include <vector>
using namespace std;

int N;
vector<string> paint;
bool visited1[101][101];
bool visited2[101][101];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void DFS1(int x, int y){
    for(int i=0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 0 || nx >= N || ny < 0 || ny >= N){
            continue;
        }
        if(paint[x][y] == paint[nx][ny] && !visited1[nx][ny]){
            visited1[nx][ny] = true;
            DFS1(nx, ny);
        }
    }
}

void DFS2(int x, int y){
    for(int i=0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 0 || nx >= N || ny < 0 || ny >= N){
            continue;
        }
        if(paint[x][y] != 'B' && paint[nx][ny] != 'B' && !visited2[nx][ny]){
            visited2[nx][ny] = true;
            DFS2(nx, ny);
        }else if(paint[x][y] == paint[nx][ny] && !visited2[nx][ny]){
            visited2[nx][ny] = true;
            DFS2(nx, ny);
        }
    }
}

int main(){
    string tmp = "";
    int cnt1 = 0;
    int cnt2 = 0;

    cin >> N;
    for(int i=0; i<N; i++){
        cin >> tmp;
        paint.push_back(tmp);
    }

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(!visited1[i][j]){
                DFS1(i, j);
                cnt1++;
            }
            if(!visited2[i][j]){
                DFS2(i, j);
                cnt2++;
            }
        }
    }
    cout << cnt1 << ' ' << cnt2;

    return 0;
}