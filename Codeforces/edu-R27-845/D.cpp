#include <iostream>
#include <stack>

using namespace std;

int main() {
    int n;
    cin >> n;
    int ans = 0, opt, x;
    int no_ovt{0};
    int speed{0};
    stack<int> limit;
    limit.push(10000);

    while (n --) {
        cin >> opt;
        switch(opt) {
            case 1:
                cin >> x;
                while (limit.top() < x) limit.pop(), ans ++;
                speed = x;
                break;
            case 2:
                ans += no_ovt;
                no_ovt = 0;
                break;
            case 3:
                cin >> x;
                if (x < speed) ans ++;
                else limit.push(x);
                break;
            case 4:
                no_ovt = 0;
                break;
            case 5:
                limit.push(10000);
                break;
            case 6:
                no_ovt ++;
                break;
            default:
                break;
        }
    }
    cout << ans << endl;
    return 0;
}