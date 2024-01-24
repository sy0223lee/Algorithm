#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    int wordCnt;
    int groupCnt = 0;
    cin >> wordCnt;

    for(int i=0; i<wordCnt; i++){
        string word;
        vector<char> abc;
        bool isGroup = true;        

        cin >> word;

        for(int j=0; j<word.length(); j++){
            auto it = find(abc.begin(), abc.end(), word[j]);
            if(it == abc.end())
                abc.push_back(word[j]);
            else if(abc[abc.size()-1] == word[j])
                continue;
            else{
                isGroup = false;
                break;
            }
        }

        if(isGroup) groupCnt++;
    }

    cout << groupCnt;

    return 0;
}