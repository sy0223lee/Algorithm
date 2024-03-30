#include <iostream>
#include <queue>
using namespace std;

int main(){
    int T = 0;
    int N = 0, M = 0;
    int idx = 0, value = 0;

    cin >> T;
    for(int t=0; t<T; t++){
        cin >> N >> M;
        queue<pair<int, int>> printerQ;
        priority_queue<int> priority;
        int cnt = 0;
        
        for(int i=0; i<N; i++){
            cin >> value;
            printerQ.push({i, value});
            priority.push(value);
        }
        while(!printerQ.empty()){
            idx = printerQ.front().first;
            value = printerQ.front().second;
            printerQ.pop();

            if(priority.top() == value){
                priority.pop();
                cnt++;
                if(M == idx){
                    cout << cnt << endl;
                    break;
                }  
            }else{
                printerQ.push({idx, value});
            }
        }
    }

    return 0;
}