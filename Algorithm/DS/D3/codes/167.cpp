// 双指针
// 左指针指向开头，右指针指向末尾。
// 计算两数和：
// 1.若和等于 target，返回 [left + 1, right + 1]（题目下标从 1 开始）。
// 2.若和小于 target，左指针右移；若和大于 target，右指针左移。
// 3.由于数组有序，以上移动策略正确且时间复杂度为 O(n)，空间复杂度 O(1)。
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	vector<int> twoSum(vector<int>& numbers, int target) {
		int left = 0;
		int right = (int)numbers.size() - 1;

		while (left < right) {
			int sum = numbers[left] + numbers[right];
			if (sum == target) {
				return {left + 1, right + 1};
			}
			if (sum < target) {
				++left;
			} else {
				--right;
			}
		}

		return {};
	}
};
