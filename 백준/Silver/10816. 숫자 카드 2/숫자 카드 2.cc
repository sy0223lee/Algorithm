#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

int main(){
    // 시간 초과 해결
    ios::sync_with_stdio(0);
    cin.tie(nullptr);

	map<int, int> m;
	int N = 0, M = 0, cardNum = 0;
	
    cin >> N;
	while (N--){
		cin >> cardNum;
		m[cardNum]++;
	}

	cin >> M;
	while (M--){
		cin >> cardNum;
		auto it = m.find(cardNum);

		if (it != m.end()){
			cout << it->second << " ";
        }
		else{
			cout << "0 ";
        }
	}
    return 0;
}