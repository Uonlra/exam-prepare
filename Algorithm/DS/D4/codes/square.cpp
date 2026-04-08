#include <iostream>
#include <string>
using namespace std;

bool horizontal_edge[10][10];
bool vertical_edge[10][10];

bool hasSquare(int row, int col, int size) {
    for (int offset = 0; offset < size; ++offset) {
        if (!horizontal_edge[row][col + offset]) return false;
        if (!horizontal_edge[row + size][col + offset]) return false;
        if (!vertical_edge[row + offset][col]) return false;
        if (!vertical_edge[row + offset][col + size]) return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n = 0;
    int problem_id = 1;
    while (cin >> n) {
        int m = 0;
        cin >> m;

        for (int i = 0; i < 10; ++i) {
            for (int j = 0; j < 10; ++j) {
                horizontal_edge[i][j] = false;
                vertical_edge[i][j] = false;
            }
        }

        for (int i = 0; i < m; ++i) {
            char type;
            int x = 0;
            int y = 0;
            cin >> type >> x >> y;
            if (type == 'H') {
                horizontal_edge[x][y] = true;
            } else {
                vertical_edge[x][y] = true;
            }
        }

        if (problem_id > 1) {
            cout << "\n**********************************\n\n";
        }
        cout << "Problem #" << problem_id << "\n\n";

        bool found = false;
        for (int size = 1; size < n; ++size) {
            int count = 0;
            for (int row = 1; row + size <= n; ++row) {
                for (int col = 1; col + size <= n; ++col) {
                    if (hasSquare(row, col, size)) {
                        ++count;
                    }
                }
            }

            if (count > 0) {
                found = true;
                cout << count << " square (s) of size " << size << "\n";
            }
        }

        if (!found) {
            cout << "No completed squares can be found.\n";
        }

        ++problem_id;
    }

    return 0;
}
