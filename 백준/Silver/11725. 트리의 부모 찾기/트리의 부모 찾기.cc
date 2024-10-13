#include <iostream>
#include <vector>
using namespace std;

int N;
vector<int> map[100001];
bool visit[100001];
int result[100001];

void DFS(int num){
    visit[num] = true;
    for(int i=0; i<map[num].size(); i++){
        int next = map[num][i];
        if(!visit[next]){
            result[next] = num;
            DFS(next);
        }
    }
}

int main(){
    int a, b;

    cin >> N;
    for(int i=1; i<N; i++){
        cin >> a >> b;
        map[a].push_back(b);
        map[b].push_back(a);
    }

    DFS(1);

    for(int i=2; i<=N; i++){
        cout << result[i] << '\n';
    }

    return 0;
}