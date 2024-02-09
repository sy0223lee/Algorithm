#include <iostream>

using namespace std;

int main(){
    int stack[10001] = {0,};

    int cmdCount;
    cin >> cmdCount;
    for(int i=0; i<cmdCount; i++){
        string cmd; cin >> cmd;

        if(cmd == "push"){
            int num; cin >> num;
            for(int j=0; j<cmdCount; j++){
                if(stack[j] == 0){
                    stack[j] = num;
                    break;
                }
            }
        }
        else if(cmd == "pop"){
            if(stack[0] == 0)
                cout << -1 << "\n";
            else{
                for(int j=1; j<cmdCount; j++){
                    if(stack[j] == 0){
                        cout << stack[j-1] << "\n";
                        stack[j-1] = 0;
                        break;
                    }
                }
            }            
        }
        else if(cmd == "size"){
            for(int j=0; j<cmdCount; j++){
                if(stack[j] == 0){
                    cout << j << "\n";
                    break;
                }
            }
        }
        else if(cmd == "empty"){
            if(stack[0] == 0)
                cout << 1 << "\n";
            else
                cout << 0 << "\n";
        }
        else if(cmd == "top"){
            if(stack[0] == 0)
                cout << -1 << "\n";
            else{
                for(int j=1; j<cmdCount; j++){
                    if(stack[j] == 0){
                        cout << stack[j-1] << "\n";
                        break;
                    }
                }
            }
        }
    }
    return 0;
}