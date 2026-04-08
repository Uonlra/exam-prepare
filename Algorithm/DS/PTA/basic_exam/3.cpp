#include <bits/stdc++.h>
using namespace std;

bool is_valid(const string& s) {
	for (char c : s) { // 遍历字符串 s 中的每个字符 c，检查是否为 'P'、'A' 或 'T'
		if (c != 'P' && c != 'A' && c != 'T') {
			return false;
		}
	}

	int p = -1, t = -1;
	for (int i = 0; i < (int)s.size(); ++i) {
		if (s[i] == 'P') {
			if (p != -1) {
				return false;
			}
			p = i;
		} else if (s[i] == 'T') {
			if (t != -1) {
				return false;
			}
			t = i;
		}
	}

	if (p == -1 || t == -1 || p > t) {
		return false;
	}

	int a = p;
	int b = t - p - 1;
	int c = (int)s.size() - t - 1;

	if (b <= 0) {
		return false;
	}
	return a * b == c;
}

int main() {
	int n;
	cin >> n;

	while (n--) {
		string s;
		cin >> s;
		cout << (is_valid(s) ? "YES" : "NO") << '\n';
	}

	return 0;
}
