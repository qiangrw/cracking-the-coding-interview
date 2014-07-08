#include <iostream>
#include <string.h>
using namespace std;

void replaceString(char *str, int len) {
    // first scan
    int space_count = 0;
    char *p = str;
    while(*p) {
        if(*p == ' ') space_count ++;
        p++;
    }
    if(space_count == 0) return;
    int extend_len = len + space_count * 2;

    // second scan
    int ei = extend_len - 1;
    int i = len - 1;
    str[extend_len] = 0;
    while(ei >= 0) {
        if(str[i] == ' ') {
            str[ei] = '0';
            str[ei-1] = '2';
            str[ei-2] = '%';
            ei -= 3;
        } else {
            str[ei] = str[i];
            ei -= 1;
        }
        i -= 1;
        if(ei == i) break;
    }
}

int main() {
    char *p = new char[100];
    strcpy(p, "hello world");
    replaceString(p, strlen(p));
    cout << p << endl;
    return 0;
}
