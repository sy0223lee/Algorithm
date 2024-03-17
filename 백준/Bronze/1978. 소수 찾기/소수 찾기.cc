#include <iostream>
#include <vector>

using namespace std;

int main(){
    int N = 0;
    int num = 0;
    bool isPrime = 0;
    int count = 0;

    cin >> N;
    for(int i=0; i<N; i++){        
        cin >> num;

        if(num == 1){
            isPrime = false;
        }else{
            isPrime = true;
            for(int j=2; j*j<=num; j++){
                if(num % j == 0){
                    isPrime = false;
                }
            }
            if(isPrime){
                count++;
            }
        }        
    }

    cout << count << endl;
    return 0;
}