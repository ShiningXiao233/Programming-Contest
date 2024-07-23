#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

const int N = 1e5+100;

int main() {
    char s[4];
    cin >> s;
    if (s[0] == 'R' || (s[1] == 'R' && s[2] == 'M')) {
        cout << "Yes";
    } else {
        cout << "No";
    }
    return 0;
}