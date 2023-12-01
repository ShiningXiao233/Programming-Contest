#include <iostream>
#include <cstring>

using namespace std;
const int N = 1e5+100, M = 2e7+100;

const int LT = 0, RT = 1000000001;

int Root[N * 3];
int idx = 0;
int n, cnt;
typedef long long ll;

struct node {
    int L, R;
    ll Sa, Sb;
}nd[M];


void upd(int &id, int upa, int upb, int L, int R, int l = LT, int r = RT) {
    if (L > r || R < l) return;
    int old = id;
    id = ++idx;
    if (old) nd[id] = nd[old];
    if (L <= l && r <= R) {
        nd[id].Sa += upa;
        nd[id].Sb += upb;
        return;
    }
    int mid = (l + r) >> 1;
    upd(nd[id].L, upa, upb, L, R, l, mid);
    upd(nd[id].R, upa, upb, L, R, mid + 1, r);
}

ll query(int id, int pos, int l = LT, int r = RT) {
    if (id == 0) return 0;
    int mid = (l + r) >> 1;
    ll tmp = pos * nd[id].Sa + nd[id].Sb;
    if (pos <= mid) {
        tmp += query(nd[id].L, pos, l, mid);
    } else {
        tmp += query(nd[id].R, pos, mid + 1, r);
    }
    return tmp;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    memset(Root, 0, sizeof(Root));
    Root[0] = idx = 1;
    cnt = 0;
    cin >> n;
    int x1, x2, a, b, y1, y2;
    ll last = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> x1 >> x2 >> y1 >> a >> b >> y2;
        cnt ++;
        Root[cnt] = Root[cnt - 1];
        upd(Root[cnt], 0, y1, LT, x1);

        cnt ++;
        Root[cnt] = Root[cnt - 1];
        upd(Root[cnt], a, b, x1 + 1, x2);

        cnt ++;
        Root[cnt] = Root[cnt - 1];
        upd(Root[cnt], 0, y2, x2 + 1, RT);
    }
    int m;
    cin >> m;
    int l, r, x;
    while (m --) {
        cin >> l >> r >> x;
        x = (1ll * x + last) % 1000000000;
        l --;
        last = query(Root[r * 3], x) - query(Root[l * 3], x);
        cout << last << '\n';
    }
    return 0;
}