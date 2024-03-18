#include <iostream>
#include <vector>

using namespace std;

int main(){
    int N, M;
    int num, tmp;
    vector<int> cards;
    cin >> N >> M;
    for(int i=0; i<N; i++){
        cin >> num;
        cards.push_back(num);
    }

    num = 0;
    for(int i=0; i<N; i++){
        for(int j=i+1; j<N; j++){
            for(int k=j+1; k<N; k++){
                tmp = cards[i] + cards[j] +cards[k];
                if(tmp <= M && tmp > num){
                    num = tmp;
                }
            }
        }
    }

    cout << num << endl;

    return 0;
}