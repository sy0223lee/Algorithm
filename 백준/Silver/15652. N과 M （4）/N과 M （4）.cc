#include <iostream>
using namespace std;

int N, M;
int arr[9];

void dfs(int num, int count) {
    if(count == M) { 
        for(int i=0; i<M; i++)
            cout << arr[i] << ' ';
        cout << '\n';
    } else {
        for(int i=num; i<=N; i++) { // 1부터 N까지
            arr[count] = i;
            dfs(i, count + 1);
        }
    }
}

int main() {
    cin >> N >> M;
    dfs(1,0);
}