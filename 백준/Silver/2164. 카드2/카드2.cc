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

    int i = 0;
    while(cards.size() > 1){
        if(i % 2 == 0){
            cards.pop();
        }else{
            num = cards.front();
            cards.pop();
            cards.push(num);
        }
        i++;
    }
    cout << cards.front() << endl;

    return 0;
}