#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int num[9];
int arr[9];
int visited[9]; // visited 배열을 이용하여 이미 사용한 숫자는 다시 사용할 수 없도록 구현

void dfs(int n, int count) {
    if(count == M) { 
        for(int i=0; i<M; i++){
            cout << num[arr[i]] << ' ';
        }
        cout << '\n';
    } else {
        for(int i=0; i<N; i++) { // 1부터 N까지
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
    for(int i=0; i<N; i++){
        cin >> num[i];
    }
    sort(num, num + N);
    dfs(0,0);
}