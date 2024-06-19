#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <string.h>
#include <sstream>
using namespace std;

int main() {
    string input;
    getline(cin , input);
    stringstream kalame(input);
    string word[10];
    int i = 0;
    while (kalame >> word[i]) {
        cout << word[i] << endl;
        i++;
    }

    return 0;
}
