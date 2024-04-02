#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main(){
    // 시간초과 해결
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    map<string, int> pokemon;
    vector<string> name;
    name.push_back("null"); // index와 포켓몬 번호를 맞춰주기 위해 임의값 push
    string tmp = "";
    int N = 0, M = 0;

    cin >> N >> M;    
    for(int i=1; i<=N; i++){
        cin >> tmp;
        pokemon.insert({tmp, i});
        name.push_back(tmp);
    }
    for(int i=0; i<M; i++){
        cin >> tmp;
        if(tmp[0] < 58){
            // 숫자가 입력된 것
            cout << name[stoi(tmp)] << '\n';
        } else{
            // 문자가 입력된 것
            cout << pokemon[tmp] << '\n';
        }
    }
    return 0;
}