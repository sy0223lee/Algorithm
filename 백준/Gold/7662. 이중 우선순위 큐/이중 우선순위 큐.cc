#include <iostream>
#include <set> // 자동적으로 오름차순 정렬
using namespace std;

int main(){
    int T; // 테스트 수
    int k; // 연산 개수
    char c; // 연산 문자
    int n; // 연산 정수

    cin >> T;
    for(int t=0; t<T; t++){
        multiset<int> Q; // 중복 허용 set
        cin >> k;

        for(int i=0; i<k; i++){
            cin >> c >> n;

            if(c == 'I'){ // insert
                Q.emplace(n);
            }else{ // delete
                if(Q.empty()){
                    continue;
                }
                if(n == 1){ // 최대값 삭제
                    // Q.erase(*Q.rbegin()); // 중복하는 최대값 있으면 다 삭제해버림
                    auto it = Q.find(*Q.rbegin());
                    Q.erase(it);
                }else{ // 최소값 삭제
                    Q.erase(Q.begin());
                }
            }
        }
        
        if(Q.empty()){
            cout << "EMPTY\n";
        }else{
            cout << *Q.rbegin() << ' ' << *Q.begin() << '\n';
        }
    }
    return 0;
}