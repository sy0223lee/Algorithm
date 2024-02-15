#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int T;
    int x1, y1, r1, x2, y2, r2;
    double d; // 두 좌표 사이의 거리

    cin >> T;
    for(int i=0; i<T; i++){
        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

        d = sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
        
        if(d == 0 && r1 == r2) // 같은 중심, 같은 거리
            cout << -1 << endl;
        else if(d == r1+r2 || d == abs(r1-r2)) // 외접 또는 내접
            cout << 1 << endl;
        else if(d > abs(r1-r2) && d < r1+r2) // 두 점에서 겹칠 때
            cout << 2 << endl;
        else
            cout << 0 << endl;
    }

    return 0;
}