#include <iostream>
using namespace std;

int main(){
    int N; // 참가자 수
    int size[6]; // 티셔츠 사이즈별 신청자 수
    int T, P; // 티셔츠 묶음 수, 펜 묶음 수
    int cntT = 0; // 티셔츠 몇 묶음 주문해야하는지

    cin >> N;
    for(int i=0; i<6; i++){
        cin >> size[i];
    }
    cin >> T >> P;

    // 티셔츠 묶음 계산
    for(int i=0; i<6; i++){
        int div = size[i] / T;
        int mod = size[i] % T;
        if(div < 1 && mod > 0){ // 묶음 수보다 작은 경우
            cntT++;
            continue;
        }else{ // 묶음 수와 같거나 큰 경우
            cntT += div;
            if(mod > 0){ // 나머지가 남은 경우 한 묶음 더 추가 구매
                cntT++;
            }
            continue;
        }
    }
    cout << cntT << endl;
    // 펜 묶음, 낱개 계산
    cout << N/P << ' ' << N%P << endl;

    return 0;
}