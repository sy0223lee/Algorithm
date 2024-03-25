#include <iostream>

using namespace std;

int main(){
    string num = "";
    string isPalin = "";

    cin >> num;
    do{
        isPalin = "yes";
        int len = num.length();
        for(int i=0; i<len/2; i++){
            if(num[i] != num[len-1-i]){
                isPalin = "no";
                break;
            }
        }
        cout << isPalin << endl;
        cin >> num;
    }while(num != "0");
    return 0;
}