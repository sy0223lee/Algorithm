#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int N;  // 사람의 수
    vector<int> P;  // 각 사람이 인출하는데 걸리는 시간
    int time, total = 0;

    cin >> N;
    for(int i=0; i<N; i++){
        cin >> time;
        P.push_back(time);
    }

    // 빨리 걸리는 사람이 먼저 수행하면 총 시간도 최소가 됨
    sort(P.begin(), P.end());
    time = 0;
    for(int i=0; i<N; i++){
        time += P[i];
        total += time;
    }
    cout << total << endl;

    return 0;
}
