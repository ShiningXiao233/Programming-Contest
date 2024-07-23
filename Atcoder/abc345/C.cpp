#include <iostream>

using namespace std;

int main() {
    int a[26] = {0};
    string s;
    cin >> s;
    long long res = 0;
    for (auto x : s) {
        a[x - 'a'] ++;
        if (a[x - 'a'] > 1) res = 1;
    }
    for (int i = 0; i < 26; ++i) 
        for (int j = i + 1; j < 26; ++j) {
            res += 1ll * a[i] * a[j];
        }
    cout << res << '\n';

    return 0;
}