#include <iostream>
#include <queue>

using namespace std;

int main(){
    int N = 0, K = 0;
    queue<int> q;
    cin >> N >> K;
    for(int i=1; i<=N; i++){
        q.push(i);
    }
    cout << "<";
    while(!q.empty()){
        for(int i=1; i<K; i++){
            q.push(q.front());
            q.pop();
        }
        cout << q.front();
        if(q.size() != 1){
            cout << ", ";
        }
        q.pop();
    }
    cout << ">" << endl;
    return 0;
}