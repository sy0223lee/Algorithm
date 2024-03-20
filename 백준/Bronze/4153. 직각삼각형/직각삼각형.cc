#include <iostream>

using namespace std;

int main(){
    int x = 0, y = 0, z = 0;

    while(true){
        cin >> x >> y >> z;
        // 0 0 0이면 종료
        if(x == 0 && y == 0 && z == 0){
            return 0;
        }
        // 세변 중 가장 긴 변 찾아서 피타고라스 정의 계산
        int result = 0;
        if(x > y){
            if(x > z){
                result = x*x - y*y - z*z;
            }else{
                result = z*z - x*x - y*y;
            }
        }else{
            if(y > z){
                result = y*y - x*x - z*z;
            }else{
                result = z*z - x*x - y*y;
            }
        }
        // 피타고라스 정의 결과에 따라 값 출력
        if(result == 0){
            cout << "right\n";
        }else{
            cout << "wrong\n";
        }
    }

    return 0;
}