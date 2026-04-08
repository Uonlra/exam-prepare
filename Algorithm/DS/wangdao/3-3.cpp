#include <bits/stdc++.h>
using namespace std;

struct Mouse {
    int weight;
    string color;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<Mouse> mice(n);
    for (int i = 0; i < n; ++i) {
        cin >> mice[i].weight >> mice[i].color;
    }

    sort(mice.begin(), mice.end(), [](const Mouse& a, const Mouse& b) {
        return a.weight > b.weight;
    });

    for (int i = 0; i < n; ++i) {
        cout << mice[i].color;
        if (i + 1 < n) {
            cout << "\n";
        }
    }

    return 0;
}
