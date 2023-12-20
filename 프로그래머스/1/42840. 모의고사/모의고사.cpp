#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    
    string p[3] = {"12345","21232425","3311224455"};
    int count[3] = {0,};
    int mod[3] = {5,8,10};
    int max = 0;

    for(int i=0; i<answers.size(); i++){
        for(int j=0; j<3; j++){
            if(answers[i] == (p[j][i%mod[j]]-48))
                count[j]++;
        }
    }

    for(int i=0; i<3; i++){
        if(max < count[i])
            max = count[i];
    }

    for(int i=0; i<3; i++){
        if(max == count[i])
            answer.push_back(i+1);
    }
    
    return answer;
}