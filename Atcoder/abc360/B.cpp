#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 1e5+100;
char s[103], t[103];
int sn, tn;

void chk(int w) {
    char tmp[103];
    
    for (int i = 0; i < w; ++i) {
        memset(tmp, 0, sizeof(tmp));
        int idx = 0, p = i;
        while(p < sn) {
            tmp[idx ++] = s[p];
            p += w;
        }
        if (strcmp(tmp, t) == 0) {
            cout << "Yes" << endl;
            exit(0);
        }
    }
}

int main() {
    cin >> s >> t;
    sn = strlen(s);
    tn = strlen(t);
    for (int i = 1; i < sn; ++i) {
        chk(i);
    }
    cout << "No" << endl;
    return 0;
}