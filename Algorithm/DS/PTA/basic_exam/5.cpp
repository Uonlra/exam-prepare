#include <bits/stdc++.h>
using namespace std;

int next_num(int n) {
	if (n % 2 == 0) {
		return n / 2;
	}
	return (3 * n + 1) / 2;
}

int main() {
	int k;
	cin >> k;

	vector<int> nums(k);
	unordered_set<int> original;
	for (int i = 0; i < k; ++i) {
		cin >> nums[i];
		original.insert(nums[i]);
	}

	unordered_set<int> covered;
	for (int x : nums) {
		int t = x;
		while (t != 1) {
			t = next_num(t);
			if (original.count(t)) {
				covered.insert(t);
			}
		}
	}

	vector<int> key_nums;
	for (int x : nums) {
		if (!covered.count(x)) {
			key_nums.push_back(x);
		}
	}

	sort(key_nums.begin(), key_nums.end(), greater<int>());
	for (int i = 0; i < (int)key_nums.size(); ++i) {
		if (i) {
			cout << ' ';
		}
		cout << key_nums[i];
	}
	cout << '\n';
	return 0;
}
