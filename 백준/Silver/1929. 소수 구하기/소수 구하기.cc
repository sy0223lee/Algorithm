#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int M, N;
    bool isPrime = true;

    cin >> M >> N;

    for(int num = M; num <= N; num++){
        if(num < 2){
            isPrime = false;
        }
        for(int div = sqrt(num); div > 1; div--){
            if(num % div == 0){
                isPrime = false;
                break;
            }
        }
        if(isPrime)
            cout << num << "\n";
        else
            isPrime = true;
    }

    return 0;
}