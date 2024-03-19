#include <iostream>

using namespace std;

int main(){
    int n, m;
    int min = 0, max = 0;

    cin >> n >> m;
    min = n > m ? m : n;
    while(true){
        if(n % min == 0 && m % min == 0){
            break;
        }
        min--;
    }
    max = (n * m) / min;

    cout << min << endl << max << endl;

    return 0;
}