//给定一个链表，返回链表开始入环的第一个节点。 如果链表无环，则返回 null。 
//
// 为了表示给定链表中的环，我们使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。 如果 pos 是 -1，则在该链表中没有环。注意，po
//s 仅仅是用于标识环的情况，并不会作为参数传递到函数中。 
//
// 说明：不允许修改给定的链表。 
//
// 进阶： 
//
// 
// 你是否可以使用 O(1) 空间解决此题？ 
// 
//
// 
//
// 示例 1： 
//
// 
//
// 
//输入：head = [3,2,0,-4], pos = 1
//输出：返回索引为 1 的链表节点
//解释：链表中有一个环，其尾部连接到第二个节点。
// 
//
// 示例 2： 
//
// 
//
// 
//输入：head = [1,2], pos = 0
//输出：返回索引为 0 的链表节点
//解释：链表中有一个环，其尾部连接到第一个节点。
// 
//
// 示例 3： 
//
// 
//
// 
//输入：head = [1], pos = -1
//输出：返回 null
//解释：链表中没有环。
// 
//
// 
//
// 提示： 
//
// 
// 链表中节点的数目范围在范围 [0, 104] 内 
// -105 <= Node.val <= 105 
// pos 的值为 -1 或者链表中的一个有效索引 
// 
// Related Topics 链表 双指针 
// 👍 985 👎 0


#include "functional"
#include "vector"
#include "assert.h"
#include "string"
#include "iostream"

using namespace std;
/**
 * https://www.cnblogs.com/season-peng/p/6713491.html
 * 求入环口 : 那么我们在第一次相遇时，把慢指针留在原地，把快指针放回起点head处，然后把快指针变为慢指针，两个指针一起以速度1前进，当它们相遇时，相遇点就是入环点4
 * 求环长度 : 那么现在从第一次相遇(k=0)开始算，一直到第二次相遇，慢指针刚好走过一个环长n，即环长等于第一次相遇到第二次相遇，慢指针走的长度。
 */
struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(nullptr) {}
};
//leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head == nullptr){
            return nullptr;
        }
        ListNode *fastNode = head;
        ListNode *slowNode = head;
        while (fastNode->next != nullptr && fastNode->next->next != nullptr) {
            slowNode = slowNode->next;
            fastNode = fastNode->next->next;
            // 有环的话
            if (slowNode == fastNode) {
                fastNode = head;
                while (slowNode != fastNode){
                    slowNode = slowNode->next;
                    fastNode = fastNode->next;
                }
                return slowNode;
            }
        }
        return nullptr;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution solution;
    // assert(solution.reverse(123) == 321);

    return 0;
}