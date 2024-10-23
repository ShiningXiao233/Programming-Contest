#include <iostream>
#include <vector>

using namespace std;

const int N = 3e5+100;

int f[N * 2], Sz[N * 2];

int fa(int x) {
    return x == f[x] ? x : f[x] = fa(f[x]);
}

void mager(int a, int b) {
    a = fa(a);
    b = fa(b);
    if (a != b) Sz[b] += Sz[a];
    f[a] = b;
}

void sol() {
    int n;
    cin >> n;
    n++;
    for (int i = 0; i < 2 * n; ++i) f[i] = i, Sz[i] = 1;
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == 'R') {
            mager(i, n + i + 1);
        } else if (s[i] == 'L') {
            mager(i + 1, n + i);
        }
    }    
    for (int i = 0; i <= s.size(); ++i) {
        cout << Sz[fa(i)] << ' ';
    }    
    cout << '\n';
}

int main() {

    int T;
    cin >> T;
    while (T --) {
        sol();
    }
    return 0;
}