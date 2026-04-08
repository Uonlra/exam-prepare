#include <bits/stdc++.h>
using namespace std;

int main() {
    string n;
    cin >> n;

    int count[10] = {0};
    for (char c : n) {
        ++count[c - '0'];
    }

    for (int digit = 0; digit <= 9; ++digit) {
        if (count[digit] > 0) {
            cout << digit << ':' << count[digit] << '\n';
        }
    }

    return 0;
}
