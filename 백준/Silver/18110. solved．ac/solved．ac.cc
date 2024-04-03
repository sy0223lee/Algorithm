#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main(){
    int n = 0;  // 난이도 의견 개수
    vector<double> opinion;    // 의견들
    double level = 0;  // 난이도
    double except = 0;

    cin >> n;
    if(n == 0){ // 의견이 없을 때 0 출력 후 종료
        cout << 0;
        return 0;
    }
    for(int i=0; i<n; i++){
        cin >> level;
        opinion.push_back(level);
    }
    sort(opinion.begin(), opinion.end());
    except = round(n * 0.15);
    level = 0;
    for(double i=except; i<n-except; i++){
        level += opinion[i];
    }
    level = round(level/(n - except*2));
    cout << level;  // cout의 특징: double형이어도 소수점 뒷자리가 0이면 int형처럼 출력됨
    return 0;
}