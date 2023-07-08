#include <iostream>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    int a = n / 5 * 5;
    int b = a + 5;
    if (n - a < b - n) {
        printf("%d\n", a);
    } else {
        printf("%d\n", b);
    }
    return 0;
}