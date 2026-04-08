// 13. Roman to Integer
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
	int romanToInt(string s) {
		unordered_map<char, int> value = { // unordered_map 用于存储罗马数字及其对应的整数值,value表示罗马数字的整数值
			{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50},
			{'C', 100}, {'D', 500}, {'M', 1000}
		};

		int ans = 0;
		for (int i = 0; i < (int)s.size(); ++i) {
			// 当前值小于后一个值时，按减法规则处理
			if (i + 1 < (int)s.size() && value[s[i]] < value[s[i + 1]]) {
				ans -= value[s[i]];
			} else {
				ans += value[s[i]];
			}
		}
		return ans;
	}
};
