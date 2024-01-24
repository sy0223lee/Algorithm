#include <iostream>
using namespace std;

int main(){
    string str;
    int count = 0;
  
    cin >> str;
  
    for(int i=0; i<str.length(); i++){
        switch (str[i]){
        case 'c':
            if(str[i+1] == '=' || str[i+1] == '-') i++;
            break;
        case 'd':
            if(str[i+1] == 'z'){
                if(str[i+2] == '=') i += 2;
            }
            else if(str[i+1] == '-') i++;
            break;
        case 'l':
            if(str[i+1] == 'j') i++;
            break;
        case 'n':
            if(str[i+1] == 'j') i++;
            break;
        case 's':
            if(str[i+1] == '=') i++;
            break;
        case 'z':
            if(str[i+1] == '=') i++;
            break;    
        default:
            break;
        }
        count++;
    }
    
    cout << count;

    return 0;
}