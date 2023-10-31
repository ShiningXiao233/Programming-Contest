#include <iostream>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;
const int N = 1e5+1000;
vector<int> a;
map<int,int> Cot;
int n;

int main() {
    int x;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        Cot[x] ++;
        a.push_back(x);
    }    
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());
    if (Cot[a[0]] >= 3) {
        cout << 1ll * Cot[a[0]] * (Cot[a[0]] - 1) * (Cot[a[0]] - 2) / 6 << endl;
    } else if (Cot[a[0]] + Cot[a[1]] >= 3) {
        if (Cot[a[0]] == 2) {
            cout << Cot[a[1]] << endl;
        } else {
            cout << 1ll * Cot[a[1]] * (Cot[a[1]] - 1) / 2 << endl;
        }
    } else {
        cout << Cot[a[2]] << endl;
    }
    
    return 0;
}