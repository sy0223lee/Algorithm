#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int N = 0, M = 0;
    string name;
    map<string, int> list;
    vector<string> dbj;
    cin >> N >> M;
    for(int i=0; i<N; i++){
        cin >> name;
        list[name]++;
    }
    for(int i=0; i<M; i++){
        cin >> name;
        if(list[name] == 1){
            dbj.push_back(name);
        }
    }
    sort(dbj.begin(), dbj.end());
    cout << dbj.size() << "\n";
    for(string s : dbj){
        cout << s << "\n";
    }
    return 0;
}