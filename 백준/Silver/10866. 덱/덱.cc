#include <iostream>
using namespace std;

int d[20002];
const int INIT_IDX = 10001;

int main(){
    int N = 0, num = 0;
    string cmd = "";
    int front = INIT_IDX, rear = INIT_IDX;
    cin >> N;

    for(int i=0; i<N; i++){
        cin >> cmd;

        if(cmd == "push_front"){
            cin >> num;
            d[--front] = num;
        }else if(cmd == "push_back"){
            cin >> num;
            d[rear++] = num;
        }else if(cmd == "pop_front"){
            if(front == rear){
                cout << -1 << "\n";
            }else{
                num = d[front];
                cout << num << "\n";
                d[front++] = 0;
            }
        }else if(cmd == "pop_back"){
            if(front == rear){
                cout << -1 << "\n";
            }else{
                num = d[--rear];
                cout << num << "\n";
                d[rear] = 0;
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
                cout << d[front] << "\n";
            }
        }else if(cmd == "back"){
            if(front == rear){
                cout << -1 << "\n";
            }else{
                cout << d[rear-1] << "\n";
            }
        }
    }
    
    return 0;
}