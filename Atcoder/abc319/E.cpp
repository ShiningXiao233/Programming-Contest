#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long ll;
const int N = 1e5 + 100;
const int MOD = 998244353;
const int FT = 840;

int X, Y, P[N], T[N];
int Q;
int n;

ll fg[FT + 10];

ll to_get(int st_time) {
    ll now_time = st_time;
    for (int i = 1; i < n; ++i) {
        if (now_time % P[i] != 0) {
            now_time += P[i] - now_time % P[i];
        }
        now_time += T[i];
    }
    return now_time - 1ll * st_time;
}

void sol() {
    cin >> n >> X >> Y;
    for (int i = 1; i < n; ++i) {
        cin >> P[i] >> T[i];
    }

    for (int i = 0; i < FT; ++i) {
        fg[i] = to_get(i);
    }

    cin >> Q;
    ll q;
    while (Q--) {
        cin >> q;
        q += X;
        q += fg[q % FT];
        q += Y;
        cout << q << endl;
    }

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