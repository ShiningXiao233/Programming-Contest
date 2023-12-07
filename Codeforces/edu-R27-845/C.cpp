#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> l(n), r(n), g(n * 2);
    for (int i = 0; i < n; ++i) {
        cin >> l[i] >> r[i];
        r[i] ++;
        g[i * 2] = l[i];
        g[i * 2 + 1] = r[i];
    }
    sort(g.begin(), g.end());
    g.erase(unique(g.begin(), g.end()), g.end());
    vector<int> sum(g.size());
    for (int i = 0; i < n; ++i) {
        l[i] = lower_bound(g.begin(), g.end(), l[i]) - g.begin();
        r[i] = lower_bound(g.begin(), g.end(), r[i]) - g.begin();
        sum[l[i]] ++;
        sum[r[i]] --;
    }
    for (int i = 1; i < sum.size(); ++i) sum[i] += sum[i - 1];
    for (int i = 0; i < sum.size(); ++i) {
        if (sum[i] > 2) {
            cout << "NO" << endl;
            exit(0);
        }
    }
    cout << "YES" << endl;
    return 0;
}