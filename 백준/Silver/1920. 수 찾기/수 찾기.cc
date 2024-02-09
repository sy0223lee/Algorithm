#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N, M, num;
    vector<int> A;

    cin >> N;
    for(int i=0; i<N; i++){
        cin >> num;
        A.push_back(num);
    }

    // binary search 사용하려면 정렬 되어 있어야 함
    sort(A.begin(), A.end());
    
    cin >> M;
    for(int i=0; i<M; i++){
        cin >> num;
        cout << binary_search(A.begin(), A.end(), num) << "\n";
    }

    return 0;
}