#include <iostream>
using namespace std;

int main(){
    int N; // I와 O가 교대로 나오는 문자열
    int M; // 입력 문자열 길이
    string S; // 입력 문자열
    string P = ""; // 찾을 문자열
    int count = 0; // P의 개수

    cin >> N >> M >> S;
    for(int i=0; i<2*N+1; i++){
        if(i%2 == 0){
            P += "I";
        }else{
            P += "O";
        }
    }

    for(int i=0; i<M; i++){
        bool flag = true;
        for(int j=0; j<P.length(); j++){
            if(S[i+j] != P[j]){
                flag = false;
                break;
            }
        }
        if(flag == true){
            count++;
        }
    }

    cout << count;  
    
    return 0;
}