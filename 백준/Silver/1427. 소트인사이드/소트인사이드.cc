#include <iostream>
#include <algorithm>
using namespace std;

bool cmp(char a, char b){
    return a > b;
}

int main(){
    string N;
    cin >> N;
    sort(N.begin(), N.end(), cmp);
    cout << N;
    return 0;
}