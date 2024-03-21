#include <iostream>

using namespace std;

int q[10001];

int main(){
    int N = 0, num = 0;
    string cmd = "";
    int front = 0, rear = 0;
    cin >> N;

    for(int i=0; i<N; i++){
        cin >> cmd;
        
        if(cmd == "push"){
            cin >> num;
            q[rear++] = num;
        }else if(cmd == "pop"){
            if(front == rear){
                cout << -1 << "\n";
            }else{
                num = q[front];
                cout << num << "\n";
                q[front++] = 0;
            }
        }else if(cmd == "size"){
            cout << rear - front << "\n";
        }else if(cmd == "empty"){
            if(front == rear){
                cout << 1 << "\n";
            }else{
                cout << 0 << "\n";
            }
        }else if(cmd == "front"){
            if(front == rear){
                cout << -1 << "\n";
            }else{
                cout << q[front] << "\n";
            }
        }else if(cmd == "back"){
            if(front == rear){
                cout << -1 << "\n";
            }else{
                cout << q[rear-1] << "\n";
            }
        }
    }
    return 0;
}