#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
	vector<vector<int>> merge(vector<vector<int>>& intervals) {
		if (intervals.empty()) { // 没有区间，直接返回空列表
			return {};
		}

		sort(intervals.begin(), intervals.end()); // 按照区间的左端点排序

		vector<vector<int>> merged;// 二维动态数组,存储合并后的区间
		merged.push_back(intervals[0]);// 将第一个区间加入结果列表
        // 从第二个区间开始遍历，尝试合并
		for (int i = 1; i < (int)intervals.size(); ++i) {
			vector<int>& last = merged.back();// 获取结果列表中最后一个区间
			int curL = intervals[i][0];
			int curR = intervals[i][1];

			if (curL <= last[1]) {
				last[1] = max(last[1], curR);
			} else {
				merged.push_back(intervals[i]);
			}
		}

		return merged;
	}
};
