#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<int,string> a, pair<int,string> b){
    return a.first < b.first;
}

int main(){
    int N;  // 회원 수
    int age;
    string name;
    vector<pair<int, string>> users;

    cin >> N;
    for(int i=0; i<N; i++){
        cin >> age >> name;
        users.push_back({age, name});
    }

    stable_sort(users.begin(), users.end(), compare);

    for(pair<int, string> u : users){
        cout << u.first << " " << u.second << "\n";
    }

    return 0;
}