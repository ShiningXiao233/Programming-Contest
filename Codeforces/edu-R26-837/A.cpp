#include <iostream>

using namespace std;

int main() {
    int n, ans = 0;
    cin >> n;
    string tmp;
    while (cin >> tmp) {
        int cnt = 0;
        for (int i = 0; i < tmp.size(); ++i) {
            if (tmp[i] >= 'A' && tmp[i] <= 'Z') {
                cnt ++;
            }
        }
        ans = max(ans, cnt);
    }
    cout << ans << endl;
    return 0;
}