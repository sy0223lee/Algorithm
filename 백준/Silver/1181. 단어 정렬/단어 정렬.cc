#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(string a, string b){
    if(a.length() == b.length()) // 길이가 같다면
        return a < b; // 사전순으로 정렬
    return a.length() < b.length(); // 길이를 오름차순으로
}

int main(){
    int N;
    vector<string> words;

    cin >> N;
    for(int i=0; i<N; i++){
        string word;
        cin >> word;
        words.push_back(word);
    }

    sort(words.begin(), words.end(), compare); // 조건대로 정렬
    words.erase(unique(words.begin(), words.end()), words.end()); // 중복값 제거

    for(string str : words){
        cout << str << endl;
    }

    return 0;
}