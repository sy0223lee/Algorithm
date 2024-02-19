#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int K, N;
long nLen;
vector<long> kLen;
// 랜선 길이를 고려하여 long형 선언

long binarySearch(long left, long right){
    if(left > right)
        return nLen;

    long mid = (left + right) / 2;
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
    long len;

    cin >> K >> N;
    for(int i=0; i<K; i++){
        cin >> len;
        kLen.push_back(len);
    }
    // sort 사용해서 메모리 2020kb보다 많이 나오는 듯?
    sort(kLen.begin(), kLen.end(), greater<>()); // 내림차순 정렬
    
    cout << binarySearch(1, kLen[0]);

    return 0;
}
