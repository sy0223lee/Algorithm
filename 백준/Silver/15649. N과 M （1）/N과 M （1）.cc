#include <iostream>
using namespace std;

int N, M;
int arr[9];
int visited[9]; // visited 배열을 이용하여 이미 사용한 숫자는 다시 사용할 수 없도록 구현

void dfs(int num, int count) {
    if(count == M) { 
        for(int i=0; i<M; i++)
            cout << arr[i] << ' ';
        cout << '\n';
    } else {
        for(int i=1; i<=N; i++) { // 1부터 N까지
            if(visited[i] == 1) continue;
            arr[count] = i;
            visited[i] = 1;
            dfs(i + 1, count + 1);
            visited[i] = 0;
        }
    }
}

int main() {
    cin >> N >> M;
    dfs(1,0);
}