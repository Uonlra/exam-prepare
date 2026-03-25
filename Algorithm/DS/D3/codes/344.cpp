// 左指针从头开始，右指针从尾开始。
// 每次交换两端字符。
// 左右指针向中间移动，直到相遇或交错。
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	void reverseString(vector<char>& s) {
		int left = 0;
		int right = (int)s.size() - 1;

		while (left < right) {
			swap(s[left], s[right]);
			++left;
			--right;
		}
	}
};
