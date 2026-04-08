#include <vector>

using namespace std;

class Solution {
public:
	void moveZeroes(vector<int>& nums) {
		int insertPos = 0;

		for (int x : nums) {
			if (x != 0) {
				nums[insertPos++] = x;
			}
		}

		while (insertPos < (int)nums.size()) {
			nums[insertPos++] = 0;
		}
	}
};
