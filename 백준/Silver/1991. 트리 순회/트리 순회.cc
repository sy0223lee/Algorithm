#include <iostream>
using namespace std;

int arr[26][2];

void preorder(int n){
    if(n == -1)
        return;
    cout << (char)(n + 'A');
    preorder(arr[n][0]);
    preorder(arr[n][1]);
}
void inorder(int n){
    if(n == -1)
        return;
    inorder(arr[n][0]);
    cout << (char)(n + 'A');
    inorder(arr[n][1]);
}
void postorder(int n){
    if(n == -1)
        return;
    postorder(arr[n][0]);
    postorder(arr[n][1]);
    cout << (char)(n + 'A');
}

int main(){
    int n;
    char root, left, right;

    cin >> n;
    for(int i=0; i<n; i++){
        cin >> root >> left >> right;
        if(left == '.')
            arr[root-'A'][0] = -1;
        else
            arr[root-'A'][0] = left-'A';
        if(right == '.')
            arr[root-'A'][1] = -1;
        else
            arr[root-'A'][1] = right-'A';
    }

    preorder(0);
    cout << '\n';
    inorder(0);
    cout << '\n';
    postorder(0);
    cout << '\n';
    
    return 0;
}