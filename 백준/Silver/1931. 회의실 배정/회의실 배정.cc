#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    vector<pair<int, int>> meet;
    int cnt = 1; // 가능한 회의 개수
    int N; // 회의의 수
    int begin, end; // 회의 시작, 회의 종료 시간

    cin >> N;

    for(int i=0; i<N; i++){
        cin >> begin >> end;
        // 종료시간을 기준으로 정렬하기 위해 end, begin으로 make pair
        meet.push_back(make_pair(end, begin));
    }
    sort(meet.begin(), meet.end());

    end = meet[0].first;
    for(int i=1; i<N; i++){
        if(end <= meet[i].second){
            cnt++;
            end = meet[i].first;
        }
    }

    cout << cnt;
    return 0;
}