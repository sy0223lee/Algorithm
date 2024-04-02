#include <iostream>
using namespace std;

int main(){
    int land[501][501] = { 0, };
    int N = 0, M = 0, B = 0;
    int dig = 0, put = 0;
    int height = 0;
    pair<int, int> result;
    cin >> N >> M >> B;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> land[i][j];
            height = max(height, land[i][j]);
        }
    }

    result = {height*2*N*M, 0};
    while(height >= 0){
        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++){
                int diff = land[i][j] - height;
                if(diff > 0){
                    dig += diff;
                }else if(diff < 0){
                    put -= diff;
                }
            }
        }
        if((dig + B) >= put){
            int time = dig*2 + put;
            if(result.first > time){
                result = {time, height};
            }
        }
        dig = 0;
        put = 0;
        height--;
    }
    cout << result.first << ' ' << result.second;
    return 0;
}