#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

class cost_flow {
public:
    static const int inf = 0x3f3f3f3f;
    cost_flow(int _n, int _m);
    ~cost_flow();
    void add(int a, int b, int c, int f) {
        flow[idx] = f; cost[idx] = c; v[idx] = b; next[idx] = head[a]; head[a] = idx ++;
        flow[idx] = 0; cost[idx] = -c; v[idx] = a; next[idx] = head[b]; head[b] = idx ++;
    }
    void EK(int init_flow = inf);
    int get_maxf() {
        return MaxF;
    }
    int S, T;
private:
    bool spfa(int init_flow);
    int *flow, *cost, *next, *v, *dis, *pre, *F, *head;
    bool *vis;
    int idx, Maxflow, MaxF;
    const int N, M;

};
const int N = 1e5+100;
int n;
int a[3004], nextMOD[8], nextval[N];

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    cost_flow res(n * 2 + 3, n * 16);
    for (int i = 1; i <= n; ++i) {
        res.add(res.S, i, 0, res.inf);
        res.add(i, i + n, 1, 1);
        res.add(i + n, res.T, 0, res.inf);
    }
    
    for (int i = n; i > 0; --i) {

        if (nextMOD[a[i] % 7] > 0) {
            res.add(i + n, nextMOD[a[i] % 7], 0, res.inf);
            res.add(i, nextMOD[a[i] % 7], 0, res.inf);
        }
        if (nextval[a[i] - 1] > 0) {
            res.add(i + n, nextval[a[i] - 1], 0, res.inf);

        } 
        if (nextval[a[i] + 1] > 0) {
            res.add(i + n, nextval[a[i] + 1], 0, res.inf);
        } 
        if (nextval[a[i]] > 0) {
            res.add(i, nextval[a[i]], 0, res.inf);
        }
        nextval[a[i]] = i;
        nextMOD[a[i] % 7] = i;
    }
    res.EK(4);
    cout << res.get_maxf() << endl;
    return 0;
}

cost_flow::cost_flow(int _n, int _m) : N(_n + 2), M(_m), S(_n), T(_n + 1), idx(0) {
    Maxflow = MaxF = 0;
    flow = new int[M]; 
    cost = new int[M]; 
    next = new int[M]; 
    v = new int[M];
    dis = new int[N];  
    pre = new int[N]; 
    F = new int[N]; 
    head = new int[N];    
    vis = new bool[N];
    memset(head, -1, sizeof(int) * N);
}

cost_flow::~cost_flow() {
    delete[] flow;
    delete[] cost;
    delete[] next;
    delete[] v;
    delete[] dis;
    delete[] pre;
    delete[] F;
    delete[] head;
    delete[] vis;    
}

void cost_flow::EK(int init_flow) {
    while (init_flow > 0 && spfa(init_flow)) {
        Maxflow += F[T];
        MaxF += F[T] * dis[T];
        init_flow -= F[T];
        int now = T;
        while (now != S) {
            flow[pre[now]] -= F[T];
            flow[pre[now] ^ 1] += F[T];
            now = v[pre[now] ^ 1];
        }
    }
}

bool cost_flow::spfa(int init_flow)
{
    memset(dis, -inf, sizeof(int) * N);
    memset(F, 0, sizeof(int) * N);
    memset(vis, 0, sizeof(bool) * N);
    dis[S] = 0;
    queue<int> _q;
    int u;
    _q.push(S);
    F[S] = init_flow;
    while (!_q.empty()) {
        u = _q.front(); _q.pop();
        vis[u] = false;
        for (int i = head[u]; ~i; i = next[i]) {
            if (flow[i] && dis[u] + cost[i] > dis[v[i]]) {
                pre[v[i]] = i;
                dis[v[i]] = dis[u] + cost[i];
                F[v[i]] = min(flow[i], F[u]);
                if (vis[v[i]]) continue;
                _q.push(v[i]);
                vis[v[i]] = true;
            }
        }
    }
    return F[T] > 0;
}
