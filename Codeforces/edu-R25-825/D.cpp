#include <iostream>
#include <cstring>
using namespace std;

const int N = 1e6+100;

char s[N], t[N];
int lens, lent;

int cnts[26], cntt[26], M;

int main() {
    cin >> s;
    cin >> t;
    lens = strlen(s);
    M = lens;
    lent = strlen(t);
    for (int i = 0; i < lens; ++i) {
        if (s[i] != '?') {
            cnts[s[i] - 'a'] ++;
            M --;
        }
    }
    
    for (int i = 0; i < lent; ++i) {
        cntt[t[i] - 'a'] ++;
    }

    int l = 0, r = lens + 1, ans = l, mid;

    auto chk = [] (int x) -> bool {
        long long m = M;
        for (int i = 0; i < 26; ++i) {
            if (1ll * cntt[i] * x > cnts[i]) {
                m -= 1ll * cntt[i] * x - cnts[i];
            }
        }
        return m >= 0;
    };

    while (l < r) {
        mid = (l + r) >> 1;
        if (chk(mid)) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid;
        }
    }

    for (int i = 0; i < 26; ++i) {
        cnts[i] = cntt[i] * ans - cnts[i];
    }
    l = 0;
    for (int i = 0; i < lens; ++i) {
        while (l < 26 && cnts[l] <= 0) ++l;
        if (s[i] == '?') {
            s[i] = l + 'a';
            cnts[l] --;
            if (l >= 26) {
                s[i] = 'a';
            }
        }
    }
    cout << s << endl;
    return 0; 
}