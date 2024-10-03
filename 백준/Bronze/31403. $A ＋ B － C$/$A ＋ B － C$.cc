#include <iostream>
using namespace std;

int main(){
    int A, B, C;
    string add;
    
    cin >> A >> B >> C;
    
    add = to_string(A) + to_string(B);

    cout << A+B-C << endl;
    cout << stoi(add)-C << endl;

    return 0;
}