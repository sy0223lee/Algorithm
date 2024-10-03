#include <iostream>
#include <queue>
using namespace std;

int main(){
    int N = 0; // 과일 개수
    int type = 0; // 과일 종류 수
    int cnt[10] = {0,}; // 과일 종류별 개수
    int answer = 0;
    queue<int> q;
    
    cin >> N;
    while(N--){
        int fruit;
        cin >> fruit;

        q.push(fruit);

        if(cnt[fruit]++ == 0){ // 처음 나온 과일인 경우 type 증가
            type++;
        }

        while(type > 2){ // 과일이 2종류 이상인 경우
            // 맨 앞에 있는 과일 제거
            fruit = q.front();
            q.pop();

            if(--cnt[fruit] == 0){ // 해당 과일을 모두 제거한 경우 type 감소
                type--;
            }
        }

        answer = max(answer, (int)q.size()); // 1 1 2 1 5 인 경우 마지막에 max(4, 2)이 됨
    }

    cout << answer;

    return 0;
}