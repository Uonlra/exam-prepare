#include <bits/stdc++.h>
using namespace std;

int main() {
	string n;
	cin >> n;

	int sum = 0;
    // 遍历字符串 n 中的每个字符 c，将其转换为对应的数字并累加到 sum 中
	for (char c : n) {
		sum += c - '0';
	}

	static const string pinyin[10] = {
		"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"
	};

	string s = to_string(sum);
	for (int i = 0; i < (int)s.size(); ++i) {
		if (i) {
			cout << ' ';
		}
		cout << pinyin[s[i] - '0'];
	}
	cout << '\n';
	return 0;
}
