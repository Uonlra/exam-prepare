#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	char ch;
	cin >> n >> ch;

	int k = 1;
	while (2 * (k + 1) * (k + 1) - 1 <= n) { // 2 * k * k - 1 <= n
		++k;
	}

	int used = 2 * k * k - 1;
	int width = 2 * k - 1;

	for (int i = width; i >= 1; i -= 2) {
		cout << string((width - i) / 2, ' ') << string(i, ch) << '\n';
	}
	for (int i = 3; i <= width; i += 2) {
		cout << string((width - i) / 2, ' ') << string(i, ch) << '\n';
	}

	cout << n - used << '\n';
	return 0;
}
