#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N; // 지도의 크기
int homeCnt; // 단지내 집의 수
vector<string> map; // 지도
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

void DFS(int x, int y){
    map[x][y] = '0'; // 방문했으면 1을 0으로 바꿈
    homeCnt++;

    for(int i=0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx < 0 || nx >= N || ny < 0 || ny >= N)
            continue;
        
        if(map[nx][ny] == '1'){
            DFS(nx, ny);
        }
    }
}

int main(){   
    vector<int> home; // 단지내 집의 수

    // map 초기화
    cin >> N;
    for(int i=0; i<N; i++){
        string str;
        cin >> str;
        map.push_back(str);
    }

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(map[i][j] == '1') {
                homeCnt = 0;
                DFS(i, j);
                home.push_back(homeCnt);
            }
        }
    }

    sort(home.begin(), home.end()); // 오름차순 정렬

    cout << home.size() << endl;
    for(int h : home){
        cout << h << endl;
    }

    return 0;
}