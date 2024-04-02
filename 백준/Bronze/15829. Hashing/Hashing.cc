#include <iostream>
using namespace std;

int main(){
    int L = 0; // 문자열의 길이
    string str = ""; // 문자열
    long long result = 0;
    
    cin >> L >> str;
    for(int i=0; i<L; i++){
        // pow 함수를 사용하면 숫자가 너무 커지는 경우 오류 발생
        // 숫자가 일정 범위를 유지하도록 곱할 때마다 mod 해주기
        long long tmp = 1;
        for(int j=0; j<i; j++){
            tmp = (tmp * 31) % 1234567891;
        }
        result += ((str[i] - 96) * tmp) % 1234567891;
        result %= 1234567891;
    }

    cout << result;
    
    return 0;
}