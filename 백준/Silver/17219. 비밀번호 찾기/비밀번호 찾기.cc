#include <iostream>
#include <map>
using namespace std;

int main(){
    // 시간초과 해결
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    map<string, string> memo;
    string site, pw;
    int N, M;

    cin >> N >> M;
    for(int i=0; i<N; i++){
        cin >> site >> pw;
        memo.insert({site, pw});
    }
    for(int i=0; i<M; i++){
        cin >> site;
        cout << memo.at(site) << "\n";
    }
    return 0;
}