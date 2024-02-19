#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int K, N;
long long nLen;
vector<long long> kLen;

long long binarySearch(long long left, long long right){
    if(left > right)
        return nLen;

    long long mid = (left + right) / 2;
    int cnt = 0;

    for(int len : kLen){
        cnt += len/mid;
    }
         
    // N개 이상으로 만들어지면 범위를 더 크게 잡기
    if(cnt >= N) {
        nLen = mid;
        return binarySearch(mid + 1, right);
    }   
    // N개 미만으로 만들어지면 범위를 더 작게 잡기
    else {
    	return binarySearch(left, mid - 1);
    }
}

int main(){
    long long len;

    cin >> K >> N;
    for(int i=0; i<K; i++){
        cin >> len;
        kLen.push_back(len);
    }
    sort(kLen.begin(), kLen.end(), greater<>()); // 내림차순 정렬
    
    cout << binarySearch(1, kLen[0]);

    return 0;
}