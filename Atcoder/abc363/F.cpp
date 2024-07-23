#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>
#include <map>
#include <stack>

using namespace std;

const int N = 1e5+100;

using ll = long long;
using Pair = pair<int, int>;
using Pairll = pair<ll, ll>;

template<typename T>
void iread(T& x, T l, T r, unsigned int rp = 1) {
    cin >> x;
    if (cin.fail()) {
        exit(122);
    }
    if (l <= x && x <= r) {
        return;
    } else {
        exit(rp);
    }
}
ll n;

map<ll, vector<ll>> f1, f2;

bool chk(ll x) {
    int len = 0, s[20];
    do {
        s[++len] = x % 10;
        x /= 10;
        if (s[len] == 0) return false;
    } while (x);
    for (int i = 1; i <= len; ++i) {
        if (s[i] != s[len - i + 1]) 
            return false;
    }
    return true;
}

bool chk_ff(ll a, ll b) {
    int lena = 0, sa[30];
    int lenb = 0, sb[30];
    while (a || b) {
        lena ++;
        lenb ++;
        sa[lena] = a % 10;
        sb[lenb] = b % 10;
        a /=10;
        b /=10;
        if (sa[lena] == 0 || sb[lenb] == 0) {
            return false;
        }
    }
    for (int i = 1; i <= lena; ++i) {
        if (sa[i] != sb[lena - i + 1]) {
            return false;
        }
    }
    return true;
}

void DP(ll n) {
    // cout << n << endl;
    if (f1.count(n) || f2.count(n)) return;
    
    f1[n] = f2[n] = vector<ll>(0);
    if (chk(n)) {
        f1[n] = vector<ll>(1, n);
    }
    for (int i = 2; n / i >= i; ++i) {
        if (n % i == 0) {
            ll a = n / i;
            ll b = i;
            DP(a);
            DP(b);
            
            if (f1[n].size() == 0) {
                if (f1[a].size() > 0 && f2[b].size() > 0) {
                    f1[n] = f2[b];
                    int k = f1[n].size();
                    f1[n].insert(f1[n].begin() + k / 2 , f1[a].begin(), f1[a].end());
                } 
                if (f2[a].size() > 0 && f1[b].size() > 0) {
                    f1[n] = f2[a];
                    int k = f1[n].size();
                    f1[n].insert(f1[n].begin() + k / 2 , f1[b].begin(), f1[b].end());
                } 
            } 
            if (f2[n].size() == 0) {
                if (chk_ff(a, b)) {
                    f2[n].push_back(a);
                    f2[n].push_back(b);
                }
                else if (f2[a].size() > 0 && f2[b].size() > 0) {
                    f2[n] = f2[b];
                    int k = f2[n].size();
                    f2[n].insert(f2[n].begin() + k / 2 , f2[a].begin(), f2[a].end());
                }
                else if (a == b && f1[a].size()) {
                    f2[n] = f1[a];
                    // if (n == 4 && a == b) {
                    //     cout << n << ' ' << " -- " << a << ' ' << b << endl;
                    //     for (int v : f2[n]) {
                    //         cout << v << ' ';
                    //     }
                    //     cout << " +++ \n";
                    // }
                    f2[n].insert(f2[n].end() , f1[a].begin(), f1[a].end());
                    // if (n == 4 && a == b) {
                    //     cout << n << ' ' << " -- " << a << ' ' << b << endl;
                    //     for (int v : f2[n]) {
                    //         cout << v << ' ';
                    //     }
                    //     cout << " +++ \n";
                    // }
                } 
            }
        }
    }

}

void sol() {
    cin >> n;
    DP(n);
    // cout << " -- " << endl;
    if (f1[n].size()) {
        ll p = -1;
        for (ll v : f1[n]) {
            if (p != -1) {
                cout << '*';
            }
            cout << v;
            p = v;
        }
    } 
    // cout << " == " << endl;
    else if (f2[n].size()) {
        ll p = -1;
        for (ll v : f2[n]) {
            if (p != -1) {
                cout << '*';
            }
            cout << v;
            p = v;
        }
    } else {
        cout << "-1" << endl;
    }
    
}

int main() {
    int T = 1;
    while (T --) {
        sol();
    }
    return 0;
}