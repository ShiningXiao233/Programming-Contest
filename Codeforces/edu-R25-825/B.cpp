#include <iostream>

using namespace std;

char s[12][12];

int main() {
    for (int i = 1; i <= 10; ++i) {
        cin >> s[i] + 1;
    }    

    auto get = [] (int X, int Y, int x, int y) -> int {
        int cnt = 0;
        while (s[X + x][Y + y] == 'X') {
            cnt ++;
            X += x;
            Y += y;
        }
        return cnt;
    };
    for (int i = 1; i <= 10; ++i) {
        for (int j = 1; j <= 10; ++j) {
            if (s[i][j] == '.') {
                if (get(i, j, 1, 0) + get(i, j, -1, 0) >= 4 ||
                    get(i, j, 0, 1) + get(i, j, 0, -1) >= 4 ||
                    get(i, j, 1, 1) + get(i, j, -1, -1) >= 4 ||
                    get(i, j, -1, 1) + get(i, j, 1, -1) >= 4
                    ) {
                    cout << "YES" << endl;
                    return 0;
                }
            }
        }
    }
    cout << "NO" << endl;
    return 0;
}