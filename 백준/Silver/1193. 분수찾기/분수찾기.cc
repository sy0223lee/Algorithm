#include <iostream>
using namespace std;

int main(){
    int x = 0;
    int i = 1;
    cin >> x;

    while(true){
        if(x - i <= 0){
            i++;
            break;
        }else{
            x -= i;
            i++;
        }
    }

    if(i % 2 == 0){ // 짝수면 i-x/x
        cout << i-x << '/' << x;
    }else{ // 홀수면 x/i-x
        cout << x << '/' << i-x;
    }

    return 0;
}