#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    bool found = false;
    for (int x = 0; x <= 100; ++x) {
        for (int y = 0; y <= 100 - x; ++y) {
            int z = 100 - x - y;

            double cost = 5.0 * x + 3.0 * y + z / 3.0;
            if (cost <= n) {
                cout << "x=" << x << ",y=" << y << ",z=" << z << "\n";
                found = true;
            }
        }
    }

    if (!found) {
        cout << "No solution";
    }

    return 0;
}
    