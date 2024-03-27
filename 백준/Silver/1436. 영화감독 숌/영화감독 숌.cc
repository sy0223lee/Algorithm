#include <iostream>
using namespace std;

int main(){
    int N = 0;
    string num = "666";
    int count = 0;
    cin >> N;
    while(true){
        if(num.find("666") != string::npos){
            count++;
            if(N == count){
                break;
            }
        }
        num = to_string(stoi(num) + 1);
    }
    cout << num << endl;
    return 0;
}