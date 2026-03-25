// 慢指针 k 指向下一个唯一值应写入的位置。
// 快指针 i 从左到右扫描。
// 仅当 nums[i] 与前一个已保留值 nums[k-1] 不同时，写入 nums[k] 并递增 k。
// 最终返回 k。
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		if (nums.empty()) {
			return 0;
		}
        // k指向下一个要放“保留元素”的位置
		int k = 1;
		for (int i = 1; i < (int)nums.size(); ++i) {
			if (nums[i] != nums[k - 1]) {
				nums[k] = nums[i];
				++k; // 只有当当前元素不等于nums[k - 1]时才增加k
			}
		}
		return k;
	}
};
