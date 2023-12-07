#include <iostream>
#include <algorithm>
using namespace std;

#include <vector>

int main() {
    int n;
    cin >> n;
    vector<int> a(n * 2);
    for_each(a.begin(), a.end(), [](int &x) {
        cin >> x;
    });
    sort(a.begin(), a.end());
    cout << ((a[n - 1] == a[n]) ? "NO" : "YES") << endl;
    return 0;
}