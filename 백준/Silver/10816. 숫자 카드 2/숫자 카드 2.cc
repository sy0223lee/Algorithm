#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
// upper_bound와 lower_bound를 이용한 이분탐색
int main(){
    // 시간 초과 해결
    ios::sync_with_stdio(0);
    cin.tie(nullptr);

	int N = 0, M = 0, cardNum = 0;
	vector<int> v;

	cin >> N;
	while (N--){
		cin >> cardNum;
		v.push_back(cardNum);
	}
    // 이분탐색을 위해 정렬
	sort(v.begin(), v.end());

	cin >> M;
	while (M--){
		cin >> cardNum;
        // upper_bound() - lower_bound()를 하여 등장한 횟수를 구할 수 있음
		cout << upper_bound(v.begin(), v.end(), cardNum)
			- lower_bound(v.begin(), v.end(), cardNum) << " ";
	}
    return 0;
}