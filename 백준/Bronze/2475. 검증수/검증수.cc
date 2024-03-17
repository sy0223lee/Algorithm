#include <iostream>

using namespace std;

int main(){
    int num = 0;
    int testNum = 0;
    
    for(int i=0; i<5; i++){
        cin >> num;
        testNum += num*num;
    }

    cout << testNum % 10 << endl;

    return 0;
}