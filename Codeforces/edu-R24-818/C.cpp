#include <iostream>

using namespace std;
const int N = 1e5+100;

int n, m, d;

struct {
    int x1, y1, x2, y2;
}a[N];
int cnt_l, cnt_r, cnt_t, cnt_b;
int sum_l[N], sum_t[N], sum_r[N], sum_b[N];

int main() {
    cin >> d;
    cin >> n >> m;
    for (int i = 1; i <= d; ++i) {
        cin >> a[i].x1 >> a[i].y1 >> a[i].x2 >> a[i].y2;
        if (a[i].x1 > a[i].x2) swap(a[i].x1, a[i].x2);
        if (a[i].y1 > a[i].y2) swap(a[i].y1, a[i].y2);
        sum_l[a[i].x1] ++;
        sum_r[a[i].x2] ++; 
        sum_t[a[i].y1] ++;
        sum_b[a[i].y2] ++;
    }
    cin >> cnt_l >> cnt_r >> cnt_t >> cnt_b;
    for (int i = 1; i < N; ++i) {
        sum_l[i] += sum_l[i - 1];
        sum_r[i] += sum_r[i - 1];
        sum_b[i] += sum_b[i - 1];
        sum_t[i] += sum_t[i - 1];
    }
    for (int i = 1; i <= d; ++i) {
        int c_l, c_r, c_b, c_t;
        c_l = sum_l[a[i].x2 - 1];
        if (a[i].x1 < a[i].x2) c_l --;

        c_r = sum_r[N - 1] - sum_r[a[i].x1];
        if (a[i].x1 < a[i].x2) c_r --;

        c_t = sum_t[a[i].y2 - 1];
        if (a[i].y1 < a[i].y2) c_t --;

        c_b = sum_b[N - 1] - sum_b[a[i].y1];
        if (a[i].y1 < a[i].y2) c_b --;

        if (cnt_l == c_l && 
            cnt_r == c_r && 
            cnt_t == c_t && 
            cnt_b == c_b) {
                cout << i << endl;
                return 0;
            }
    }
    cout << -1 << endl;
    return 0;
}