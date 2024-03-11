#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

bool compare(pair<int, int> a, pair<int, int> b){
    if(a.second == b.second){
        return a.first < b.first;
    }
    return a.second > b.second;
}

int main(){
    int N; // N개의 수
    vector<pair<int, int>> nums;   // 숫자들 저장하기 위한 벡터
    int sum = 0;    // 산술평균을 구하기 위한 합
    int mean, median, mode, range;   // 산술평균, 중앙값, 최빈값, 범위

    cin >> N;
    for(int i=0; i<N; i++){
        int num;
        cin >> num;
        nums.push_back(make_pair(num, 1));
        sum += num;
    }
    sort(nums.begin(), nums.end());
    // 산술평균
    mean = round((double) sum / N);
    // 중앙값
    median = nums[N/2].first;
    // 범위
    range = nums[N-1].first - nums[0].first;

    // 최빈값    
    for(int i=1; i<N; i++){
        if(nums[i].first == nums[i-1].first){
            nums[i].second = nums[i-1].second + 1;
        }
    }
    sort(nums.begin(), nums.end(), compare);
    if(nums[0].second == nums[1].second){
        mode = nums[1].first;
    }else{
        mode = nums[0].first;
    }

    cout << mean << endl;
    cout << median << endl;
    cout << mode << endl;
    cout << range << endl;

    return 0;
}