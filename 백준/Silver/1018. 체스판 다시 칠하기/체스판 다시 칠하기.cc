#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> board; // N*M의 체스판
string WB[8] = {
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW"
};
string BW[8] = {
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB"
};

int checkColor(int x, int y, string *arr){
    int count = 0;
    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            if(board[x+i][y+j] != arr[i][j]){
                count++;
            }
        }
    }
    return count;
}

int main(){
    int N = 0, M = 0;
    int result = 64;

    cin >> N >> M;
    for(int i=0; i<N; i++){
        string str = "";
        cin >> str;
        board.push_back(str);
    }

    for(int i=0; i<=N-8; i++){
        for(int j=0; j<=M-8; j++){
            int count = min(checkColor(i,j,WB), checkColor(i,j,BW));
            if(result > count){
                result = count;
            }
        }
    }

    cout << result << endl;

    return 0;
}