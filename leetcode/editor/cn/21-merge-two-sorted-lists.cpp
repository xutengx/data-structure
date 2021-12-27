//将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 
//
// 
//
// 示例 1： 
//
// 
//输入：l1 = [1,2,4], l2 = [1,3,4]
//输出：[1,1,2,3,4,4]
// 
//
// 示例 2： 
//
// 
//输入：l1 = [], l2 = []
//输出：[]
// 
//
// 示例 3： 
//
// 
//输入：l1 = [], l2 = [0]
//输出：[0]
// 
//
// 
//
// 提示： 
//
// 
// 两个链表的节点数目范围是 [0, 50] 
// -100 <= Node.val <= 100 
// l1 和 l2 均按 非递减顺序 排列 
// 
// Related Topics 递归 链表 👍 2110 👎 0


#include "iostream"
#include "cassert"
#include "vector"
#include "string"
#include "functional"

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
//leetcode submit region begin(Prohibit modification and deletion)
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

    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
        auto *head = new ListNode();

        function<void(ListNode *, ListNode *, ListNode *)> mergeTwoListsReal;
        mergeTwoListsReal = [&mergeTwoListsReal](ListNode *node0, ListNode *node1, ListNode *node2) {
            if (node1 != nullptr && node2 != nullptr) {
                if (node1->val < node2->val) {
                    node0->next = node1;
                    mergeTwoListsReal(node0->next, node1->next, node2);
                } else {
                    node0->next = node2;
                    mergeTwoListsReal(node0->next, node1, node2->next);
                }
            } else if (node1 == nullptr) {
                node0->next = node2;
            } else {
                node0->next = node1;
            }
        };

        mergeTwoListsReal(head, list1, list2);
        return head->next;

    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution solution;
    // 
    return 0;
}