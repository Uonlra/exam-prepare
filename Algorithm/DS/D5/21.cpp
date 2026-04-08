/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode dummy;
        ListNode* tail = &dummy; // dummy节点用于简化边界情况的处理，tail指向结果链表的最后一个节点

        while (list1 != nullptr && list2 != nullptr) {// 当两个链表都不为空时，比较当前节点的值，并将较小的节点连接到结果链表中
            if (list1->val <= list2->val) {
                tail->next = list1;
                list1 = list1->next;
            } else {
                tail->next = list2;
                list2 = list2->next;
            }
            tail = tail->next; // 更新tail指向结果链表的最后一个节点
        }

        if (list1 != nullptr) { // 如果list1还有剩余节点，直接连接到结果链表的末尾
            tail->next = list1;
        } else { // 如果list2还有剩余节点，直接连接到结果链表的末尾
            tail->next = list2;
        }

        return dummy.next;
    }
};