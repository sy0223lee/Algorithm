#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Point{
    int x;
    int y;
};
bool compare(Point p1, Point p2){
    if(p1.y == p2.y){
        return p1.x < p2.x;
    }
    // 오름차순
    return p1.y < p2.y;
}
int main(){
    int N = 0;
    int x = 0, y = 0;
    vector<Point> pos;
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> x >> y;
        pos.push_back({x, y});
    }
    sort(pos.begin(), pos.end(), compare);
    
    for(Point p : pos){
        cout << p.x << " " << p.y << "\n";
    }
    return 0;
}