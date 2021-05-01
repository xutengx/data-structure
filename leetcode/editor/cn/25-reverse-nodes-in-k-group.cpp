//给你一个链表，每 k 个节点一组进行翻转，请你返回翻转后的链表。 
//
// k 是一个正整数，它的值小于或等于链表的长度。 
//
// 如果节点总数不是 k 的整数倍，那么请将最后剩余的节点保持原有顺序。 
//
// 进阶： 
//
// 
// 你可以设计一个只使用常数额外空间的算法来解决此问题吗？ 
// 你不能只是单纯的改变节点内部的值，而是需要实际进行节点交换。 
// 
//
// 
//
// 示例 1： 
//
// 
//输入：head = [1,2,3,4,5], k = 2
//输出：[2,1,4,3,5]
// 
//
// 示例 2： 
//
// 
//输入：head = [1,2,3,4,5], k = 3
//输出：[3,2,1,4,5]
// 
//
// 示例 3： 
//
// 
//输入：head = [1,2,3,4,5], k = 1
//输出：[1,2,3,4,5]
// 
//
// 示例 4： 
//
// 
//输入：head = [1], k = 1
//输出：[1]
// 
//
// 
// 
//
// 提示： 
//
// 
// 列表中节点的数量在范围 sz 内 
// 1 <= sz <= 5000 
// 0 <= Node.val <= 1000 
// 1 <= k <= sz 
// 
// Related Topics 链表 
// 👍 1071 👎 0


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
    ListNode *reverseKGroup(ListNode *head, int k) {
        if (k == 1) {
            return head;
        }
        ListNode *flagNode, *fNode, *bNode, *tempNode, *tempNodeHead, *tNode;
        int counter = 0;

        // 新建哨兵节点
        flagNode = new ListNode;
        flagNode->next = head;
        // 新建临时哨兵节点
        tempNodeHead = new ListNode;

        // 初始化前一节点
        fNode = flagNode;
        // 循环结束指针
        bNode = flagNode;
        while (bNode != nullptr) {
            if (++counter > k) {
                // 反转局部链表 begin
                // 临时链表头
                tempNodeHead->next = bNode->next;

                // 通过了计数的，肯定不为 nullptr
                while (--counter > 0) {

                    // 原节点头出 begin
                    tempNode = fNode->next;
                    fNode->next = tempNode->next;
                    // 原节点头出 end

                    // 新链表头入 begin
                    tempNode->next = tempNodeHead->next;
                    tempNodeHead->next = tempNode;
                    // 新链表头入 end
                }

                // 链表头接上原链
                fNode->next = tempNodeHead->next;
                // 反转局部链表 end

                // 下次翻转的前一节点
                int cc = k;
                while (cc-- > 1) {
                    tempNode = tempNode->next;
                }
                bNode = fNode = tempNode;
            }else{
                bNode = bNode->next;
            }
        }

        return flagNode->next;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution solution;
    // 
    ListNode *n1 = new ListNode(1);
    ListNode *n2 = new ListNode(2);
    ListNode *n3 = new ListNode(3);
    ListNode *n4 = new ListNode(4);
    ListNode *n5 = new ListNode(5);
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    ListNode *pNode = solution.reverseKGroup(n1, 3);
    return 0;
}