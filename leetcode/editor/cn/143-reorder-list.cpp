//给定一个单链表 L 的头节点 head ，单链表 L 表示为： 
//
// 
//L0 → L1 → … → Ln - 1 → Ln
// 
//
// 请将其重新排列后变为： 
//
// 
//L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → … 
//
// 不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。 
//
// 
//
// 示例 1： 
//
// 
//
// 
//输入：head = [1,2,3,4]
//输出：[1,4,2,3] 
//
// 示例 2： 
//
// 
//
// 
//输入：head = [1,2,3,4,5]
//输出：[1,5,2,4,3] 
//
// 
//
// 提示： 
//
// 
// 链表的长度范围为 [1, 5 * 10⁴] 
// 1 <= node.val <= 1000 
// 
// Related Topics 栈 递归 链表 双指针 👍 744 👎 0


#include "iostream"
#include "cassert"
#include "vector"
#include "string"
#include "functional"
#include "stack"

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
     * 链表中点 + 链表逆序 + 合并链表
     * @param head
     */
    void reorderList(ListNode *head) {
        // 快慢指针链表找中点
        ListNode * fast = head;
        ListNode * slow = head;
        while (fast->next != nullptr &&  fast->next->next != nullptr ){
            slow = slow->next;
            fast = fast->next->next;
        }
        // 链表中点
        ListNode * mid = slow->next;
        // 断开连接
        slow->next = nullptr;

        // 链表逆序
        ListNode * prev = nullptr;
        ListNode * cu = mid;
        while (cu != nullptr){
            ListNode *nextTemp = cu->next;
            cu->next = prev;

            prev  = cu;
            cu = nextTemp;
        }
        // 逆序列表头
        ListNode * l2 = prev;

        ListNode * l1 = head;
        // 链表合并
        ListNode* l1_tmp;
        ListNode* l2_tmp;
        while (l1 != nullptr && l2 != nullptr){
            l1_tmp = l1->next;
            l2_tmp = l2->next;

            l1->next = l2;
            l1 = l1_tmp;
            l2->next = l1;
            l2 = l2_tmp;
        }
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution c;
    // 
    ListNode *one = new ListNode(1);
    ListNode *two = new ListNode(2);
    ListNode *three = new ListNode(3);
    ListNode *four = new ListNode(4);
    ListNode *five = new ListNode(5);

    one->next = two;
    two->next = three;
    three->next = four;
    four->next = five;

    c.reorderList(one);

    return 0;
}