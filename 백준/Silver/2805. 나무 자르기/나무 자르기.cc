#include <iostream>
#include <vector>
#include <algorithm> // sort

using namespace std;

int N; // 나무의 수
long M; // 필요한 나무의 길이
long H; // 절단 높이
vector<long> height; // 나무의 높이

long binarySearch(long low, long high){
    if(low > high)
        return H;

    long mid = (low + high) / 2;
    long len = 0; // 잘린 나무의 길이
    for(long i : height){
        len += i > mid ? i-mid : 0;
    }
    
    if(len >= M){
        H = mid;
        return binarySearch(mid + 1, high);
        
    }
    else
    	return binarySearch(low, mid - 1);
}

int main(){
    cin >> N >> M;
    for(int i=0; i<N; i++){
        long h; cin >> h;
        height.push_back(h);
    }
    sort(height.begin(), height.end());

    cout << binarySearch(0, height[N-1]);

    return 0;
}