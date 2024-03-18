#include <iostream>

using namespace std;

int main(){
    int N = 0;
    int count = 0;
    cin >> N;

    int range = 1;
    int i = 0;
    while(true){
        range += 6 * i;
        if(range >= N){
            count = i + 1;
            break;
        }
        i++;
    }

    cout << count << endl;

    return 0;
}