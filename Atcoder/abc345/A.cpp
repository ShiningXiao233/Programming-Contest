#include <iostream>

using namespace std;

int main() {
    string a;
    cin >> a;
    for (int i = 0; i < a.size(); ++i) {
        if (i == 0 && a[i] == '<') {

        } else if (i == a.size() - 1 && a[i] == '>') {

        } else if (i > 0 && i < a.size() - 1 && a[i] == '=') {

        } else {
            cout << "No" << '\n';
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}