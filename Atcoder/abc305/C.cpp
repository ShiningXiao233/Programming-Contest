#include <iostream>

using namespace std;
char s[506][506];
int n, m;

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        scanf("%s", s[i] + 1);
    }    
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            int ff = 0;
            ff += (s[i - 1][j] == '#');
            ff += (s[i + 1][j] == '#');
            ff += (s[i][j - 1] == '#');
            ff += (s[i][j + 1] == '#');
            if (s[i][j] == '.' && ff >= 2) {
                printf("%d %d", i, j);
                return 0;
            }
        }
    }
    return 0;
}