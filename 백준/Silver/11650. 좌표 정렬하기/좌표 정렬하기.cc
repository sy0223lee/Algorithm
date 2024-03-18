#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<int,int> pos1, pair<int,int> pos2){
    if(pos1.first == pos2.first){
        return pos1.second < pos2.second;
    }
    return pos1.first < pos2.first;
}

int main(){
    int N;  // 점의 개수
    int x, y;   // 좌표
    vector<pair<int, int>> pos;

    cin >> N;
    for(int i=0; i<N; i++){
        cin >> x >> y;
        pos.push_back({x, y});
    }

    sort(pos.begin(), pos.end(), compare);

    for(pair<int, int> p : pos){
        cout << p.first << " " << p.second << "\n";    // endl 시간초과 발생
    }    

    return 0;
}