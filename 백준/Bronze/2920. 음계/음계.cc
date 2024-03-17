#include <iostream>

using namespace std;

int main(){
    int sound[8] = {0,};
    string result = "";
    for(int i=0; i<8; i++){
        cin >> sound[i];
    }

    if(sound[0] == 1){  // ascending 인지 검사
        result = "ascending";
        for(int i=1; i<8; i++){
            if(sound[i-1] > sound[i]){
                result = "mixed";
                break;
            }
        }
    }
    else if(sound[0] == 8){ // descending 인지 검사
        result = "descending";
        for(int i=1; i<8; i++){
            if(sound[i-1] < sound[i]){
                result = "mixed";
                break;
            }
        }
    }
    else{   // mixed
        result = "mixed";
    }

    cout << result << endl;

    return 0;
}