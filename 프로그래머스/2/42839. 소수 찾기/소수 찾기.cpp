#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool isPrime(int n){
    if(n < 2)
        return false;
    for(int i=2; i*i <= n; i++){
        if(n%i == 0){
            return false;
        }
    }
    return true;
}

int solution(string numbers) {
    int answer = 0;    
    vector<int> num;

    sort(numbers.begin(), numbers.end());

    do{
        string tmp = "";

        for(int i=0; i<numbers.size(); i++){
            tmp.push_back(numbers[i]);
            num.push_back(stoi(tmp));
        }
    } while(next_permutation(numbers.begin(), numbers.end()));

    sort(num.begin(), num.end());
    num.erase(unique(num.begin(), num.end()), num.end());

    for(auto a : num){
        if(isPrime(a))
            answer++;
    }
    
    return answer;
}