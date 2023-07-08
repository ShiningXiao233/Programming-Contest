#include <iostream>

using namespace std;
const int x[] = {0, 3, 4, 8, 9, 14, 23};

int main() {
    char a, b;
    scanf("%c %c ", &a, &b);
    if (a > b) swap(a, b);
    a -= 'A';
    b -= 'A';
    printf("%d\n", x[b] - x[a]);    
    return 0;
}