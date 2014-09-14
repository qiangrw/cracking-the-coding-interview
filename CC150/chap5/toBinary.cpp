#include <iostream>
#include <sstream>
#include <string>

using namespace std;

string toBinary(double num) {
    ostringstream oss;
    if(num >= 1 || num <=0) return "ERROR";
    int len = 0;
    double r;
    while(num > 0) {
        if(len >= 32) return "ERROR";
        r = num * 2;
        if(r >= 1) {
            num = r-1; 
            oss << 1;
        } else {
            num = r;
            oss << 0;
        }
    }
    return oss.str();
}

int main() {
    cout << toBinary(0.5) << endl;
    cout << toBinary(0.55) << endl;
    cout << toBinary(0.75) << endl;
    cout << toBinary(0.72) << endl;
    cout << toBinary(0.111111111111111111111111111111111) << endl;
    cout << toBinary(2.111111111111111111111111111111111) << endl;
}
