#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main(){
    int N = 0; // 좌표 개수
    vector<int> pos;
    vector<int> tmp;
    cin >> N;
    for(int i=0; i<N; i++){
        int num = 0;
        cin >> num;
        pos.push_back(num);
        tmp.push_back(num);
    }
    sort(tmp.begin(), tmp.end());
    tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());    
    
    for(int i=0; i<N; i++){
        cout << lower_bound(tmp.begin(), tmp.end(), pos[i]) - tmp.begin() << ' ';
    }

    return 0;
}