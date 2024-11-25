#include <iostream>

int main() {
    using ll = long long;
    ll a, b, p;
    std::cin >> a >> b >> p;
    auto pow = [](ll a, ll b, ll p) -> ll {
        ll res = 0;
        for (; b; b >>= 1) {
            if (b & 1) res = (res + a) % p;
            a = (a + a) % p;
            // std::cout << a << '\n';
        }
        return res;
    };
    std::cout << pow(a, b, p) << '\n';
    return 0;
}