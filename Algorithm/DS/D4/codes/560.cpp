#include <vector>

using namespace std;

class Solution {
public:
	int subarraySum(vector<int>& nums, int k) {
		int n = (int)nums.size();
		vector<int> prefix(n + 1, 0);//初始化前缀和数组，长度为n+1，prefix[0] = 0
        // 计算前缀和，prefix[i]表示前i个元素的和
        for (int i = 0; i < n; ++i) {
			prefix[i + 1] = prefix[i] + nums[i];
		}
        // 统计满足条件的子数组数量
		int count = 0;
		for (int l = 0; l < n; ++l) {
			for (int r = l; r < n; ++r) {
				if (prefix[r + 1] - prefix[l] == k) {
					++count;
				}
			}
		}

		return count;
	}
};
