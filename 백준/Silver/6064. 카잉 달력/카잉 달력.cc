#include <iostream>
using namespace std;

// 최대공약수
int gcd(int a, int b){
    if(b == 0){
        return a;
    }else{
        return gcd(b, a % b);
    }
}
// 최소공배수
int lcm(int a, int b){
    return a * b / gcd(a, b);
}

int main(){
    int T, M, N, x, y;
    cin >> T;
    for(int t=0; t<T; t++){
        cin >> M >> N >> x >> y;

        int cnt = -1, mi = lcm(M, N);
        for(int i=x; i<=mi; i+=M){
            int ny = i % N;
            if(ny == 0) ny = N;

            if(ny == y){
                cnt = i;
                break;
            }
        }
        cout << cnt << '\n';
    }
    return 0;
}