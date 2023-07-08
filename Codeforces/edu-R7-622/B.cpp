#include <cstdio>

using namespace std;

int main() {
	int hh, mm, k;
	scanf("%d:%d %d", &hh, &mm, &k);
	mm += k;
	hh += mm / 60;
	mm %= 60;
	hh %= 24;
	printf("%02d:%02d", hh, mm);
	return 0;
}
