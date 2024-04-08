#include <iostream>
#include <vector>
using namespace std;

vector<vector<bool>> paper;
int wCnt, bCnt;

void check(int x, int y, int n){
    bool white = false;
    bool blue = false;
    for(int i=x; i<x+n; i++){
        for(int j=y; j<y+n; j++){
            if(paper[i][j] == 0){
                white = true;
            }
            if(paper[i][j] == 1){
                blue = true;
            }
        }
    }
    if(white && !blue){
        wCnt++;
    }else if(!white && blue){
        bCnt++;
    }else{
        n /= 2;
        check(x, y, n);
        check(x + n, y, n);
        check(x, y + n, n);
        check(x + n, y + n, n);
    }
}

int main(){
    int N = 0;
    bool color = 0;
    cin >> N;
    for(int i=0; i<N; i++){
        vector<bool> tmp;
        for(int j=0; j<N; j++){            
            cin >> color;
            tmp.push_back(color);
        }
        paper.push_back(tmp);
    }
    check(0, 0, N);
    cout << wCnt << '\n' << bCnt;
    return 0;
}