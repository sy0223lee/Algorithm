#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int K, N;
long nLen;
vector<long> kLen;
// 랜선 길이의 범위를 고려해서 long형을 사용해야 함

long binarySearch(long left, long right){
    while(left <= right){
        long mid = (left+right)/2;
        int cnt = 0;

        for(int len : kLen){
            cnt += len/mid;
        }

        if(cnt >= N){
            nLen = mid;
            left = mid + 1;
        }
        else
            right = mid - 1;
    }

    return nLen;
}

int main(){
    long len;

    cin >> K >> N;
    for(int i=0; i<K; i++){
        cin >> len;
        kLen.push_back(len);
    }
    sort(kLen.begin(), kLen.end(), greater<>()); // 내림차순 정렬
    
    cout << binarySearch(1, kLen[0]);

    return 0;
}