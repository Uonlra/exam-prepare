#include <bits/stdc++.h>
using namespace std;

struct Student {
	string name;
	string id;
	int score;
};

int main() {
	int n;
	cin >> n;

	Student top, low;
	top.score = -1;
	low.score = 101;

	for (int i = 0; i < n; ++i) {
		Student s;
		cin >> s.name >> s.id >> s.score;
		if (s.score > top.score) {
			top = s;
		}
		if (s.score < low.score) {
			low = s;
		}
	}

	cout << top.name << ' ' << top.id << '\n';
	cout << low.name << ' ' << low.id << '\n';
	return 0;
}
