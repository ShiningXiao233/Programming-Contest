#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;
const int N = 2e5+100;

struct Data_t
{
    int rating;
    int id, timex;
    bool operator < (const Data_t& rhs) const {
        return rating < rhs.rating;
    }
    bool operator > (const Data_t& rhs) const {
        return rating > rhs.rating;
    }
};

int time_st[N], time_sch[N], belong[N];
int rtg[N];

priority_queue<Data_t, vector<Data_t>, less<Data_t> > q[N];
priority_queue<Data_t, vector<Data_t>, greater<Data_t> > tg;

int main() {
    int n, Q, a, b, c, d;
    cin >> n >> Q;
    for (int i = 1; i <= n; ++i) {
        cin >> a >> b;
        rtg[i] = a;
        belong[i] = b;
        q[b].push({a, i, time_st[i]});
    } 
    for (int i = 1; i < N; ++i) {
        if (q[i].size()) {
            tg.push({q[i].top().rating, i, time_sch[i]});
        }
    }
    // cout << tg.top().rating << endl;
    for (int i = 1; i <= Q; ++i) {
        cin >> c >> d;
        time_sch[belong[c]] ++;
        time_st[c] ++;
        while (!q[belong[c]].empty() && q[belong[c]].top().timex < time_st[q[belong[c]].top().id]) {
            q[belong[c]].pop();
        }
        if (!q[belong[c]].empty()) {
            tg.push({q[belong[c]].top().rating, belong[c], time_sch[belong[c]]});
        }
        
        belong[c] = d;
        q[d].push({rtg[c], c, time_st[c]});
        time_sch[d] ++;
        tg.push({q[d].top().rating, d, time_sch[d]});

        while (!tg.empty() && tg.top().timex < time_sch[tg.top().id]) {
            tg.pop();
        }
        cout << tg.top().rating << endl;
        // time_sch[d] ++;
        
    }
    return 0;
}