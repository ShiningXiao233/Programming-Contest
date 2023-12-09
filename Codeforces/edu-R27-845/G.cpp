#include <iostream>

using namespace std;

int n, m;

int f[34];

void update(int x) {
    for (int i = 30; i >= 0; --i) {
        if (x >> i & 1) {
            if (f[i] == 0) {
                f[i] = x;
                break;
            }
            else x ^= f[i];
        }
    }
}

#include <vector>
#include <tuple>
#include <algorithm>
#include <cstring>

using pr = pair<int, int>;
using tg = tuple<int, int, int>;

const int N = static_cast<int>(1e5+10);
vector<tg> G[N], mp;

int dis[N];

void dfs(int u = 1, int fa = 0) {    
    for (const tg &x : G[u]) {
        if (dis[get<0>(x)] == -1) {
            dis[get<0>(x)] = dis[u] ^ get<1>(x);
            dfs(get<0>(x), u);
            mp[get<2>(x)] = make_tuple(-1, -1, -1);
        }    
    }    
}

int main() {
    cin >> n >> m;
    mp.resize(m);
    int u, v, w;
    for (int i = 0; i < m; ++i) {
        cin >> u >> v >> w;
        G[u].push_back(make_tuple(v, w, i));
        G[v].push_back(make_tuple(u, w, i));
        mp[i] = make_tuple(u, v, w);
    }
    memset(dis, -1, sizeof(dis));
    dis[1] = 0;
    dfs();
    for_each(mp.begin(), mp.end(), [](const tg& x) {
        if (get<0>(x) > -1) {
            update(dis[get<0>(x)] ^ dis[get<1>(x)] ^ get<2>(x));
        }
    });
    int ans = dis[n];
    for (int i = 30; i >= 0; --i) {
        if ((ans >> i & 1)) {
            ans ^= f[i];
        }
    }
    cout << ans << endl;
    return 0;
}