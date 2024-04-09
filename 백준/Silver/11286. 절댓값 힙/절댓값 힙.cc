#include <iostream>
#include <queue>
using namespace std;

struct compare{
    bool operator()(int x, int y){
        if(abs(x) == abs(y)){
            return x > y;
        }
        return abs(x) > abs(y);
    }
};

int main(){
    // 시간초과 해결
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    // priority_queue<자료형, 구현체, 비교연산자>
    priority_queue<int, vector<int>, compare> pq;

    int N = 0, x = 0;
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> x;
        if(x == 0){
            if(pq.empty()){
                cout << 0 << '\n';
            }else{
                cout << pq.top() << '\n';
                pq.pop();
            }
        }else{
            pq.push(x);
        }
    }

    return 0;
}