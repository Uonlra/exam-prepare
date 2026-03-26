#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int minPrice = 100000; // 价格范围是 [0, 10^4]
		int best = 0;
        // 遍历价格列表，更新最小价格和最大利润
		for (int price : prices) {
			minPrice = min(minPrice, price);
			best = max(best, price - minPrice);
		}

		return best;
	}
};
