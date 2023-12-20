#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    vector<int> w;
    vector<int> h;
    
    for(auto a : sizes){
        if(a[0] > a[1]){
            w.push_back(a[0]);
            h.push_back(a[1]);
        }
        else{
            w.push_back(a[1]);
            h.push_back(a[0]);
        }
    }
    
    answer = (*max_element(w.begin(),w.end())) * (*max_element(h.begin(),h.end()));

    return answer;
}