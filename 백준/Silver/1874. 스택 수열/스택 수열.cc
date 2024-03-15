#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main(){
    int n;
    int num = 1;
    vector<int> seq; // 주어진 수열
    vector<char> result; // +, - 결과
    stack<int> st;  // 스택

    cin >> n;
    for(int i=1; i<=n; i++){
        int tmp;
        cin >> tmp;
        seq.push_back(tmp);
    }

    st.push(0);
    for(int i=0; i<n; i++){
        if(st.top() == seq[i]){ // 스택.top이랑 동일하면 pop
            st.pop();
            result.push_back('-');
        }else if(st.top() > seq[i]){    // 스택.top이 더 크면 불가능
            cout << "NO" << endl;
            return 0;
        }else{  // 스택.top보다 크면 수열[i]까지 push
            for(int j=num; j<=seq[i]; j++){
                st.push(j);
                result.push_back('+');
                num++;
            }
            st.pop();
            result.push_back('-');
        }
    }
    for(char c : result){
        cout << c << "\n";    // 시간초과 발생으로 endl을 \n로 수정
    }
    return 0;
}