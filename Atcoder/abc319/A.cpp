#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <map>


using namespace std;

typedef long long ll;
const int N = 1e5 + 100;
const int MOD = 998244353;

map<string, int> mp;

void sol() {
    mp["tourist"] = 3858;
    mp["ksun48"] = 3679;
    mp["Benq"] = 3658;
    mp["Um_nik"] = 3648;
    mp["apiad"] = 3638;
    mp["Stonefeang"] = 3630;
    mp["ecnerwala"] = 3613;
    mp["mnbvmar"] = 3555;
    mp["newbiedmy"] = 3516;
    mp["semiexp"] = 3481;
    string f;
    cin >> f;
    cout << mp[f];
}

int main() {
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    // cout.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) {
        sol();
    }
    exit(0);
}