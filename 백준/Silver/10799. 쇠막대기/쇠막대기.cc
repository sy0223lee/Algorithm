#include <iostream>
#include <stack>
using namespace std;

int main(){
    stack<char> st;
    string str;
    int count = 0;

    cin >> str;
    for(int i=0; i<str.length(); i++){
        char c = str[i];
        if(c == '(' && str[i+1] == ')'){
            count += st.size();
            i++;
        }else if(c == ')'){
            st.pop();
            count++;
        }else{
            st.push(c);
        }
    }
    cout << count;
    return 0;
}