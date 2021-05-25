//给你单链表的头节点 head ，请你反转链表，并返回反转后的链表。
// 
// 
// 
//
// 示例 1： 
//
// 
//输入：head = [1,2,3,4,5]
//输出：[5,4,3,2,1]
// 
//
// 示例 2： 
//
// 
//输入：head = [1,2]
//输出：[2,1]
// 
//
// 示例 3： 
//
// 
//输入：head = []
//输出：[]
// 
//
// 
//
// 提示： 
//
// 
// 链表中节点的数目范围是 [0, 5000] 
// -5000 <= Node.val <= 5000 
// 
//
// 
//
// 进阶：链表可以选用迭代或递归方式完成反转。你能否用两种方法解决这道题？ 
// 
// 
// Related Topics 链表 
// 👍 1754 👎 0


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
    /**
     * 解答成功:
     * 执行耗时:12 ms,击败了19.06% 的C++用户
     * 内存消耗:8 MB,击败了90.43% 的C++用户
     */
    ListNode *reverseList(ListNode *head) {
        // 新链表的哨兵
        auto *newHead = new ListNode;
        // 原链表的哨兵
        auto *oldHead = new ListNode;
        oldHead->next = head;

        while (oldHead->next != nullptr) {
            // 原链表头出
            ListNode *temp = oldHead->next;
            oldHead->next = oldHead->next->next;
            // 新链表头入
            ListNode *pNode = newHead->next;
            newHead->next = temp;
            newHead->next->next = pNode;
        }
        return newHead->next;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution solution;
    // 
    return 0;
}