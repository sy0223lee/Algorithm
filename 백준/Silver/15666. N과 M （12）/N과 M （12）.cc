#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, M;
vector<int> num;
// int num[9];
int arr[9];

void dfs(int n, int count) {
    if(count == M) { 
        for(int i=0; i<M; i++){
            cout << num[arr[i]] << ' ';
        }
        cout << '\n';
    } else {
        for(int i=n; i<num.size(); i++) { // 1부터 num 벡터의 사이즈
            arr[count] = i;
            dfs(i, count + 1);
        }
    }
}

int main() {
    int tmp;
    cin >> N >> M;
    for(int i=0; i<N; i++){
        cin >> tmp;
        num.push_back(tmp);
    }
    sort(num.begin(), num.end());
    // 중복 제거 - erase 함수는 vector 에만 존재하므로 배열 대신 벡터 사용
    num.erase(unique(num.begin(), num.end()), num.end());
    dfs(0,0);
}