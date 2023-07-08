#include <iostream>

using namespace std;

int main() {
	long long n;
	cin >> n;
	int p = 1;
	while (p < n) {
		n -= p;
		p ++;
	}
	cout << n << '\n';
}
