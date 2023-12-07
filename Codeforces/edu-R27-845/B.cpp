#include <iostream>

using namespace std;

int main() {
    char s[7];
    cin >> s;
    int ans = 10;
    for (int i = 0; i < 1000000; ++i) {
        int x = i, a = 0, b = 0, tmp = 0;
        for (int j = 0; j < 3; ++j) {
            if (x % 10 != s[j] - '0') tmp ++;
            a += x % 10;
            x /= 10;
        } 
        for (int j = 0; j < 3; ++j) {
            if (x % 10 != s[j + 3] - '0') tmp ++;
            b += x % 10;
            x /= 10;
        } 
        if (a == b) {
            ans = min(ans, tmp);
        }
    }
    cout << ans << endl;
    return 0;
}