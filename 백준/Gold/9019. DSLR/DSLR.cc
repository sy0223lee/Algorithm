#include <iostream>
#include <queue>
using namespace std;

int main(){
    int T;
    cin >> T;
    for(int t=0; t<T; t++){
        int A, B, result;
        queue<pair<int, string>> q;
         // 메모리 초과 해결을 위해 같은 숫자에 대한 연산을 제외하기 위한 배열 선언
        bool visited[10000] = {0,};
        cin >> A >> B;

        // BFS
        q.push({A, ""});
        visited[A] = true;
        while(!q.empty()){
            int n = q.front().first;
            string cmd = q.front().second;
            q.pop();

            // n이 최종값과 같으면 출력, while문 탈출
            if(n == B){
                cout << cmd << "\n";
                break;
            }

            // D
            result = (n * 2) % 10000;
            if(!visited[result]){
                q.push({result, cmd + "D"});
                visited[result] = true;
            }
            // S
            result = (n == 0 ? 9999 : n-1);
            if(!visited[result]){
                q.push({result, cmd + "S"});
                visited[result] = true;
            }
            // L
            result = (n % 1000) * 10 + n / 1000;
            if(!visited[result]){
                q.push({result, cmd + "L"});
                visited[result] = true;
            }
            // R
            result = n / 10 + (n % 10) * 1000;
            if(!visited[result]){
                q.push({result, cmd + "R"});
                visited[result] = true;
            }
        }
    }
    return 0;
}