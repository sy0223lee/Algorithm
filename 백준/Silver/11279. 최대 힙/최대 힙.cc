#include <iostream>
#include <queue>
using namespace std;

int main(){
    // 시간초과 대비
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N = 0; // 연산 개수
    priority_queue<int> pq; // 우선순위 큐, 큰 수가 높은 우선순위
    cin >> N;
    for(int i=0; i<N; i++){
        int num = 0;
        cin >> num;
        if(num == 0){
            if(pq.empty()){
                cout << "0\n";
            }else{
                cout << pq.top() << '\n';
                pq.pop();
            }
        }else{
            pq.push(num);
        }
    }
    return 0;
}