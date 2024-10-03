#include <iostream>
using namespace std;

int main(){
    string input[3];
    int num;

    for(int i=0; i<3; i++){
        cin >> input[i];
    }
    // 다음에 올 숫자 구하기
    for(int i=0; i<3; i++){
        if(input[i][0] < 65){ // 스트링의 첫번째 문자가 알파벳(아스키코드)보다 작은 경우
            num = stoi(input[i]);
            num += 3-i;
            break;
        }
    }

    // 다음에 올 숫자를 문자열로 변경하기
    if(num % 15 == 0){
        cout << "FizzBuzz" << endl;
    }else if(num % 3 == 0){
        cout << "Fizz" << endl;
    }else if(num % 5 == 0){
        cout << "Buzz" << endl;
    }else{
        cout << num << endl;
    }

    return 0;
}