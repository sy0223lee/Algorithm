#include <iostream>
#include <stack>

using namespace std;

int main(){
    int K = 0;
    int num = 0;
    int sum = 0;
    stack<int> st;

    cin >> K;
    for(int i=0; i<K; i++){
        cin >> num;
        if(num == 0){
            st.pop();
        }else{
            st.push(num);
        }
    }
    while(!st.empty()){
        sum += st.top();
        st.pop();
    }

    cout << sum << endl;

    return 0;
}