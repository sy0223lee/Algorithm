#include <iostream>
#include <map>
#include <string>
using namespace std;

int main(){
    double totalGrade = 0.0;
    double totalRate = 0.0;
    string lecture;
    double grade;
    string rate;
    map<string, double> rates;
    rates["A+"] = 4.5; rates["A0"] = 4.0; rates["B+"] = 3.5;
    rates["B0"] = 3.0; rates["C+"] = 2.5; rates["C0"] = 2.0;
    rates["D+"] = 1.5; rates["D0"] = 1.0; rates["F"]  = 0.0;

    for(int i=0; i<20; i++){
        cin >> lecture >> grade >> rate;

        if(rate != "P"){
            totalGrade += grade;
            totalRate += grade * rates.find(rate)->second;
        }
    }

    cout << totalRate/totalGrade;

    return 0;
}