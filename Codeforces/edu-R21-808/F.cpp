#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

class _flow {
public:
    static const int INF = 1000000000;
    _flow(int n, int m);
    ~_flow();
    int get_Max_flow() {
        int res = 0;
        while (find_way()) res += toflow(S, INF);
        return res;
    }
    void add(int a, int b, int c1 = INF, int c2 = 0) {
        v[idx] = b, flow[idx] = c1, next[idx] = head[a], head[a] = idx ++;
        v[idx] = a, flow[idx] = c2, next[idx] = head[b], head[b] = idx ++;
    }
    void set_S(int x) {
        S = x;
    }
    void set_T(int x) {
        T = x;
    }
    int get_S() const {
        return S;
    }
    int get_T() const {
        return T;
    }
private:
    bool find_way();
    int toflow(int u, int limt);
    const int N, M;
    int *v, *next, *flow, *cur, *head, *dep;
    int S, T, idx;
};

int n, k;

int p[103], c[103], l[103];
const int LIM = 2e5+10;
bool prime[LIM];


bool chk(int x) {
    int res = 0, tl = 0;
    for (int i = 1; i <= n; ++i) {
        if (l[i] <= x && c[i] == 1 && p[i] > p[tl]) tl = i;
    }
    for (int i = 1; i <= n; ++i) {
        if (l[i] <= x) {
            if (c[i] == 1) {
                if (tl == i) res += p[i];
            } else {
                res += p[i];
            }
        }
    }
    _flow mc(n + 1, 2 * ((n + 3) * (n + 3)));
    for (int i = 1; i <= n; ++i) {
        if (l[i] <= x) {
            if (c[i] & 1) { // odd
                if ((c[i] == 1 && tl == i) || c[i] > 1) {
                    mc.add(i, mc.get_T(), p[i]);
                }
            } else { // even
                mc.add(mc.get_S(), i, p[i]);
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (l[i] > x) continue;
        if (c[i] == 1 && i != tl) continue;
        for (int j = i + 1; j <= n; ++j) {
            if (l[j] > x) continue;
            if (c[j] == 1 && j != tl) continue;
            if (prime[c[i] + c[j]] == 0) {
                if (c[i] % 2 == 0)
                    mc.add(i, j);
                else mc.add(j, i);
            }
        }
    }
    res -= mc.get_Max_flow();
    return res >= k;
}

int main() {
    prime[1] = 1;
    for (int i = 2; i < LIM; ++i) {
        for (int j = i + i; j < LIM; j += i) {
            prime[j] = 1;
        }
    }
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> p[i] >> c[i] >> l[i];
    }
    int ctl = 1, ctr = n, mid, ans = -1;
    while (ctl <= ctr) {
        mid = (ctl + ctr) >> 1;
        if (chk(mid)) {
            ans = mid;
            ctr = mid - 1;
        } else {
            ctl = mid + 1;
        }
    }
    cout << ans << '\n';
    return 0;
}

_flow::_flow(int n, int m) : N(n + 2), M(m), S(n), T(n + 1), idx(0) {
    v = new int[M];
    next = new int[M];
    flow = new int[M];
    cur = new int[N];
    head = new int[N];
    dep = new int[N];
    memset(head, -1, sizeof(int) * N);
}

_flow::~_flow() {
    delete[] v;
    delete[] next;
    delete[] flow;
    delete[] cur;
    delete[] head;
    delete[] dep;
}

bool _flow::find_way() {
    memset(dep, -1, sizeof(int) * N);
    queue<int> q;
    dep[S] = 1; q.push(S); cur[S] = head[S];
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int i = head[u]; ~i; i = next[i]) {
            if (dep[v[i]] == -1 && flow[i]) {
                dep[v[i]] = dep[u] + 1;
                cur[v[i]] = head[v[i]];
                if (v[i] == T) return true;
                q.push(v[i]);
            }
        }
    }
    return false;
}

int _flow::toflow(int u, int limt) {
    if (u == T) return limt;
    int res{0}, tmp;
    for (int i = cur[u]; ~i; i = next[i]) {
        cur[u] = i;
        if (dep[v[i]] == dep[u] + 1 && flow[i] > 0) {
            tmp = toflow(v[i], min(limt, flow[i]));
            if (tmp == 0) dep[v[i]] = -1;
            flow[i] -= tmp; flow[i ^ 1] += tmp;
            limt -= tmp; res += tmp;
        }
    }
    return res;
}   
