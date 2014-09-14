#include <iostream>
#include <string>
#include <sstream>
using namespace std;

string compress(string str) {
    int len = str.size();
    if(len <= 1) return str;
    ostringstream oss;
    char cur = str[0];
    int cnt = 1;
    for(int i=1; i<len; ++i) {
        if(str[i] != cur) {
            oss << cur << cnt;
            cnt = 0;
            cur = str[i];
        }
        cnt += 1;
    }
    // last char
    oss << cur << cnt;
    string res = oss.str();
    if(res.size() > str.size()) return str;
    else return res;
}

int main() {
    cout << compress("aabcccccaaa") << endl;
    return 0;
}
