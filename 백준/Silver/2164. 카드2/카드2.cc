#include <iostream>
#include <queue>

using namespace std;

int main(){
    queue<int> cards;
    int num = 0;
    cin >> num;
    for(int i=1; i<=num; i++){
        cards.push(i);
    }

    while(cards.size() > 1){
        cards.pop();
        num = cards.front();
        cards.pop();
        cards.push(num);
    }
    cout << cards.front() << endl;

    return 0;
}