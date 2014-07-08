#include <iostream>
#include <string.h>
using namespace std;

void reverse(char *str) {
    char *start=str, *end=str;
    while(*end) ++end;
    end --;
    while(start < end) {
        swap(*start, *end);
        start++;
        end--;
    }

}

int main() {
    char *str = new char[20];
    strcpy(str, "hello world");
    reverse(str);
    cout << str << endl;
}
