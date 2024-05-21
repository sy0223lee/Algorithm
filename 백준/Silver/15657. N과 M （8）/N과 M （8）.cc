#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int num[9];
int arr[9];

void dfs(int n, int count) {
    if(count == M) { 
        for(int i=0; i<M; i++){
            cout << num[arr[i]] << ' ';
        }
        cout << '\n';
    } else {
        for(int i=n; i<N; i++) { // 1부터 N까지
            arr[count] = i;
            dfs(i, count + 1);
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