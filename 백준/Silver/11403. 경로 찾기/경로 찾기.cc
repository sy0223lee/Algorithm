#include <iostream>
#include <vector>
using namespace std;

int N;
vector<int> map[100];
bool visited[100];

void DFS(int i){    
    for(int j=0; j<map[i].size(); j++){
        if(!visited[map[i][j]]){
            visited[map[i][j]] = true;  
            DFS(map[i][j]);
        }
    }
}

int main(){
    cin >> N;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            int tmp;
            cin >> tmp;
            if(tmp == 1){
                map[i].push_back(j);
            }
        }
    }
    for(int i=0; i<N; i++){
        DFS(i);
        for(int j=0; j<N; j++){
            cout << visited[j] << ' ';
            visited[j] = 0;
        }
        cout << '\n';
    }
    return 0;
}