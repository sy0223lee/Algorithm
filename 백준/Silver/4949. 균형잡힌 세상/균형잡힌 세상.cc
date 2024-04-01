#include <iostream>
#include <stack>
using namespace std;

int main(){
    string str = "";
    int len = 0;
    
    while(true){
        getline(cin, str); // 공백 포함, 개행 미포함 입력 받기
        if(str == "."){
            break;
        }
        stack<char> st;
        len = str.length();

        for(int i=0; i<len; i++){
            if(str[i] == '(' || str[i] == '['){
                st.push(str[i]);
            }else if(str[i] == ')'){
                if(!st.empty() && st.top() == '('){
                    st.pop();
                }else{
                    cout << "no\n";
                    break;
                }
            }else if(str[i] == ']'){
                if(!st.empty() && st.top() == '['){
                    st.pop();
                }else{
                    cout << "no\n";
                    break;
                }
            }else if(str[i] == '.'){
                if(st.empty()){
                    cout << "yes\n";
                }else{
                    cout << "no\n";
                }
            }
        }        
    }
    return 0;
}