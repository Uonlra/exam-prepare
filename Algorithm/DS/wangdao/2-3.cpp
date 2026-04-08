#include <iostream>
using namespace std;

int main() {
	int N, X, Y, Z;

	while (cin >> N >> X >> Y >> Z) {
		int bestTotal = -1;
		int bestA = -1;
		int bestB = -1;

		for (int a = 1; a <= 9; ++a) {
			for (int b = 0; b <= 9; ++b) {
				int total = a * 10000 + X * 1000 + Y * 100 + Z * 10 + b;
				if (total % N == 0) {
					if (total > bestTotal) {
						bestTotal = total;
						bestA = a;
						bestB = b;
					}
				}
			}
		}

		if (bestTotal == -1) {
			cout << 0;
		} else {
			cout << bestA << " " << bestB << " " << bestTotal / N;
		}

		if (!cin.eof()) {
			cout << "\n";
		}
	}

	return 0;
}
