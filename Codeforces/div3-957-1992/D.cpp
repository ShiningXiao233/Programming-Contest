#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <tuple>

using namespace std;

void solve() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        long long k;
        cin >> n >> m >> k;
        string a;
        cin >> a;

        vector<char> river(n + 2); // Positions from 0 to n+1
        river[0] = 'B';           // Left bank
        river[n + 1] = 'B';       // Right bank
        for (int i = 1; i <= n; ++i) {
            river[i] = a[i - 1];
        }

        vector<vector<bool>> visited(n + 2, vector<bool>(2, false)); // visited[position][in_water]
        queue<tuple<int, long long, bool>> queue; // (position, swim_left, in_water)
        queue.emplace(0, k, false);
        visited[0][0] = true;
        bool success = false;

        while (!queue.empty()) {
            int pos;
            long long swim_left;
            bool in_water;
            tie(pos, swim_left, in_water) = queue.front();
            queue.pop();

            if (pos == n + 1) {
                cout << "YES" << endl;
                success = true;
                break;
            }

            if (in_water) {
                int new_pos = pos + 1;
                if (new_pos <= n + 1 && river[new_pos] != 'C' && !visited[new_pos][1]) {
                    visited[new_pos][1] = true;
                    if (river[new_pos] == 'W') {
                        if (swim_left > 0) {
                            queue.emplace(new_pos, swim_left - 1, true);
                        }
                    } else {
                        queue.emplace(new_pos, swim_left, false);
                    }
                }
            } else {
                for (int jump = 1; jump <= m; ++jump) {
                    int new_pos = pos + jump;
                    if (new_pos > n + 1) {
                        cout << "YES" << endl;
                        success = true;
                        break;
                    }
                    if (river[new_pos] == 'C' || visited[new_pos][0]) continue;
                    visited[new_pos][0] = true;
                    if (river[new_pos] == 'W') {
                        if (swim_left > 0) {
                            queue.emplace(new_pos, swim_left - 1, true);
                        }
                    } else {
                        queue.emplace(new_pos, swim_left, false);
                    }
                }
                if (success) break;
            }
        }
        if (!success) {
            cout << "NO" << endl;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}