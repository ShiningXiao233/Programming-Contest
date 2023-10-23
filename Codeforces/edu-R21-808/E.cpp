#include <iostream>
#include <algorithm>

using namespace std;
const int N = 1e5+100;
int n, m;

int w1[N], cnt1;
int w2[N], cnt2;
int w3[N], cnt3;
typedef long long ll;

bool cmp(int a, int b) {
    return a > b;
}
bool cmpll(ll a, ll b) {
    return a > b;
}

ll tmp2[N];

ll get_ans(int *w1, int *w2, int *w3, int cnt1, int cnt2, int cnt3, int m) {
    ll res = 0, t3{}, t2{}, xtmp, tp = 0, gg;
    for (int i = 0; i + 1 < cnt1; i += 2) {
        tmp2[t2 ++] = w1[i] + w1[i + 1];
    }
    for (int i = 0; i < cnt2; ++i) {
        tmp2[t2 ++] = w2[i];
    }
    sort(tmp2, tmp2 + t2, cmpll);
    for (int i = 1; i < t2; ++i) tmp2[i] += tmp2[i - 1];
    tp = 0;
    for (int i = 0; i <= cnt3; ++i) {
        if (i * 3 <= m) {
            xtmp = tp;
            gg = (m - i * 3) / 2;
            if (gg > t2) gg = t2;
            --gg;
            if (gg >= 0) xtmp += tmp2[gg];
            res = max(res, xtmp);
        }
        tp += w3[i];
    }
    return res;
}

int main() {
    cin >> n >> m;
    int w, c;
    for (int i = 1; i <= n; ++i) {
        cin >> w >> c;
        if (w == 1) {
            w1[cnt1++] = c;
        } else if (w == 2) {
            w2[cnt2++] = c;
        } else if (w == 3) {
            w3[cnt3++] = c;
        }
    }
    sort(w1, w1 + cnt1, cmp);
    sort(w2, w2 + cnt2, cmp);
    sort(w3, w3 + cnt3, cmp);
    long long ans = 0, tmp;
    tmp = get_ans(w1, w2, w3, cnt1, cnt2, cnt3, m);
    ans = max(ans, tmp);
    tmp = get_ans(w1 + 1, w2, w3, cnt1 - 1, cnt2, cnt3, m - 1) + w1[0];
    ans = max(ans, tmp);
    cout << ans << endl;
    return 0;
}