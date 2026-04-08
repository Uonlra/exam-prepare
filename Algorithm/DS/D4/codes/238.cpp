#include <vector>

using namespace std;

class Solution {
public:
	vector<int> productExceptSelf(vector<int>& nums) {
		int n = (int)nums.size();
		vector<int> answer(n, 1);// 初始化结果数组长度为n，默认值为1

		int prefix = 1;
		for (int i = 0; i < n; ++i) {
			answer[i] = prefix;
			prefix *= nums[i]; // 更新前缀积，包含当前元素
		}

		int suffix = 1;
		for (int i = n - 1; i >= 0; --i) {
			answer[i] *= suffix;
			suffix *= nums[i];// 更新后缀积，包含当前元素
		}

		return answer;
	}
};
