#include <iostream>

using namespace std;

int main() {
    unsigned int a, b;
    while (cin >> a >> b) {
        a &= 0xFFFF;
        b &= 0xFFFF;

        bool ok = false;
        unsigned int cur = a;
        for (int i = 0; i < 16; ++i) {
            if (cur == b) {
                ok = true;
                break;
            }
            cur = ((cur << 1) & 0xFFFF) | ((cur >> 15) & 1);
        }

        cout << (ok ? "YES" : "NO") << '\n';
    }
    return 0;
}