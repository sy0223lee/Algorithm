#include <iostream>
#include <vector>

using namespace std;

struct Person{
    int x; // 몸무게
    int y; // 키
    int rank = 1; // 등수
};
int main(){
    int N = 0;
    vector<Person> p;
    cin >> N;
    for(int i=0; i<N; i++){
        int x, y;
        cin >> x >> y;
        p.push_back({x, y});
    }

    for(int i=0; i<N; i++){
        for(int j=i+1; j<N; j++){
            if(p[i].x > p[j].x && p[i].y > p[j].y){
                p[j].rank++;
            }else if(p[i].x < p[j].x && p[i].y < p[j].y){
                p[i].rank++;
            }
        }
    }

    for(Person ps: p){
        cout << ps.rank << " ";
    }
    return 0;
}