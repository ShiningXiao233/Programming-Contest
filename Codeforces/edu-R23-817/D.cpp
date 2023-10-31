#include <iostream>

using namespace std;
const int N = 1e6+100;
int Tmax[N], Tmin[N];
typedef long long ll;
int a[N];

int main() {
    int n, x;
    ll ans = 0, SumMax = 0, SumMin = 0;
    cin >> n;
    int cntMax = 0, cntMin = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> x;
        a[i] = x;
        while (cntMax > 0 && x >= a[Tmax[cntMax]]) {
            SumMax -= 1ll * a[Tmax[cntMax]] * (Tmax[cntMax] - Tmax[cntMax - 1]);
            --cntMax;
        }
        SumMax += 1ll * (i - Tmax[cntMax]) * x;
        Tmax[++cntMax] = i;

        while (cntMin > 0 && x <= a[Tmin[cntMin]]) {
            SumMin -= 1ll * a[Tmin[cntMin]] * (Tmin[cntMin] - Tmin[cntMin - 1]);
            --cntMin;
        }
        
        SumMin += 1ll * (i - Tmin[cntMin]) * x;
        Tmin[++cntMin] = i;
        
        ans += SumMax - SumMin;

        // for (int j = 0; j <= cntMax; ++j) {
        //     cout << "(" << Tmax[j] << ',' << a[Tmax[j]] << "),"; 
        // }
        // cout << endl;
        // for (int j = 0; j <= cntMin; ++j) {
        //     cout << "(" << Tmin[j] << ',' << a[Tmin[j]] << "),"; 
        // }
        // cout << endl;
        // cout << " ---- " << endl;
    }
    cout << ans << endl;
    return 0;
}