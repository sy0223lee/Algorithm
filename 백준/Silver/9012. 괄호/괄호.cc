#include <iostream>

using namespace std;

int main(){
    int T;
    cin >> T;

    for(int i=0; i<T; i++){
        char stack[51] = {0,};
        int idx = 0;
        string str;
        cin >> str;

        for(int j=0; j<str.length(); j++){
            if(str[j] == '('){
                stack[idx] = '(';
                idx++;
            }
            else{
                if(stack[idx-1] == '('){
                    stack[idx-1] = 0;
                    idx--;
                }
                else{
                    stack[idx] = ')';
                    idx++;
                }
            }
        }

        if(stack[0] == 0)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}