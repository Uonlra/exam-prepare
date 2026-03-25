/* 双指针
1.从左到右扫描数组。
2.遇到不等于 val 的元素，就写到 nums[k]，然后 k 加一。
3.最后 k 就是不等于 val 的元素个数，且前 k 个位置就是有效结果。
4.k 之后的内容不重要，符合题目要求。
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k = 0;  // 指向下一个要放“保留元素”的位置
        for (int i = 0; i < (int)nums.size(); i++) {
            if (nums[i] != val) {
                nums[k] = nums[i];
                k++; // 只有当当前元素不等于val时才增加k
            }
        }
        return k;
    }
};