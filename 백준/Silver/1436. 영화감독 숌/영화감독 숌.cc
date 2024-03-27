#include <iostream>
using namespace std;

int main(){
    int N = 0;
    int num = 665;
    cin >> N;
    while(N > 0){
        num++;
        string strNum = to_string(num);
        if(strNum.find("666") != string::npos){
            N--;
        }
    }
    cout << num << endl;
    return 0;
}