#include <iostream>
using namespace std;

void parseJson(string str) {
    auto it = str.begin();
    bool has_left = false;
    int level = 0;
    string temp;
    while (it != str.end()) {
        if (*it == '\'') {
            if (has_left) {
                cout << temp;
                temp = "";
                has_left = false;
            } else {
                has_left = true;
            }
        } else if (*it == ':') {
            cout << ":";
        } else if (*it == '[') {
            level += 4;
            cout << endl << string(level, ' ') << "[" << endl;
            cout << string(level, ' ');
        } else if (*it == ']') {
            cout << endl << string(level, ' ') << "]" << endl;
            level -= 4;
        } else if (*it == '{' || *it == '}') {
            // do nothing
        } else if (*it == ',') {
            cout << endl;
            cout << string(level, ' ');
        } else {
            temp += *it;
        }
        ++it;
    }
}

int main() {
    string str = "{'a':'1','b':['c':'2','d':'3','e':['f':'6','g':'7']]}";
    parseJson(str);
    return 0;
}
