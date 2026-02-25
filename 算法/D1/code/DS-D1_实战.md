# DS-D1

slug: ds-1
上次编辑: 2026年2月6日 19:23
创建时间: 2026/01/16
标识: 实战-1
状态: 完成

# 规划

1. 语法学习
    - [x]  建立模板
    - [x]  **基本类型 + 运算 + 控制语句**
    - [x]  **一维数组的基本使用**
2. leetcode实战
    - [x]  **两数之和（简单数组 + 循环）**
    - [x]  **回文数（基本类型 + while）**
    - [x]  **合并两个有序数组（数组 + 指针）**

# 训练

## [两数之和](https://leetcode.cn/problems/two-sum/description/)

```c
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    if (nums == NULL || numsSize < 2 || returnSize == NULL) {
        if (returnSize) *returnSize = 0;
        return NULL;
    }

    for (int i = 0; i < numsSize - 1; i++) {
        for (int j = i + 1; j < numsSize; j++) {
            if (nums[i] + nums[j] == target) {
                int* res = (int*)malloc(2 * sizeof(int));
                if (res == NULL) {         // 内存分配失败的安全检查
                    *returnSize = 0;
                    return NULL;
                }
                res[0] = i;               // 返回 0-based 下标
                res[1] = j;
                *returnSize = 2;
                return res;
            }
        }
    }

    *returnSize = 0; // 未找到
    return NULL;
}
```

---

## [两数相加](https://leetcode.cn/problems/add-two-numbers)

```c
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode dummy;           // 哑节点，方便统一操作
    struct ListNode *tail = &dummy;  // 当前链表尾指针
    dummy.next = NULL;

    int carry = 0;
    while (l1 != NULL || l2 != NULL || carry != 0) {
        int sum = carry;
        if (l1) { sum += l1->val; l1 = l1->next; }
        if (l2) { sum += l2->val; l2 = l2->next; }

        carry = sum / 10;
        struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
        if (node == NULL) {
            // 内存分配失败：释放已构造的节点并返回 NULL
            struct ListNode* p = dummy.next;
            while (p) {
                struct ListNode* tmp = p->next;
                free(p);
                p = tmp;
            }
            return NULL;
        }
        node->val = sum % 10;
        node->next = NULL;

        tail->next = node;
        tail = node;
    }

    return dummy.next;
}
```

---

## [回文数](https://leetcode.cn/problems/palindrome-number/)

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        if (x % 10 == 0 && x != 0) return false;

        int reverted = 0;
        while (x > reverted) {
            reverted = reverted * 10 + x % 10;
            x /= 10;
        }
        return x == reverted || x == reverted / 10;
    }
};
```

# 数组

1. [合并两个有序数组](https://leetcode.cn/problems/merge-sorted-array/)
    
    ```cpp
    //使用三个指针从末尾向前合并
    #include <bits/stdc++.h>
    using namespace std;
    
    class Solution {
    public:
        void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
            int p1 = m - 1;         // 指向 nums1 有效区末尾
            int p2 = n - 1;         // 指向 nums2 末尾
            int p = m + n - 1;      // 指向合并后数组末尾（nums1 的末尾）
    
            // 从后向前填充，避免覆盖 nums1 中尚未处理的元素
            while (p2 >= 0) {
                if (p1 >= 0 && nums1[p1] > nums2[p2]) {
                    nums1[p--] = nums1[p1--];
                } else {
                    nums1[p--] = nums2[p2--];
                }
            }
        }
    };
    ```
    
2. [只出现一次的数字](https://leetcode.cn/problems/single-number/)

```cpp
// 使用位运算异或（XOR）性质：a ^ a = 0，a ^ 0 = a，
// 因此把数组中所有数异或，成对出现的数会抵消，剩下的就是只出现一次的数。

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for (int v : nums) ans ^= v;
        return ans;
    }
};
```