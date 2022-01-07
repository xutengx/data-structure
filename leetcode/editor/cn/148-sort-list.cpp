//给你链表的头结点 head ，请将其按 升序 排列并返回 排序后的链表 。 
//
// 
// 
//
// 
//
// 示例 1： 
//
// 
//输入：head = [4,2,1,3]
//输出：[1,2,3,4]
// 
//
// 示例 2： 
//
// 
//输入：head = [-1,5,3,4,0]
//输出：[-1,0,3,4,5]
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
// 链表中节点的数目在范围 [0, 5 * 10⁴] 内 
// -10⁵ <= Node.val <= 10⁵ 
// 
//
// 
//
// 进阶：你可以在 O(n log n) 时间复杂度和常数级空间复杂度下，对链表进行排序吗？ 
// Related Topics 链表 双指针 分治 排序 归并排序 👍 1426 👎 0


#include "iostream"
#include "cassert"
#include "vector"
#include "string"
#include "functional"

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

using namespace std;

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
     * 归并排序 (稳定排序 空间O(n) 时间O(nlog(n))
     * 如果要排序一个数组，我们先把数组从中间分成前后两部分，然后对前后两部分分别排序，再将排好序的两部分合并在一起，这样整个数组就都有序了。
     */
    ListNode *sortList(ListNode *head) {
        return realSortList(head, getSize(head));
    }

private:
    /**
     * 获取链表长度
     * @param node
     * @return
     */
    int getSize(ListNode *node) {
        int count = 0;
        while (node != nullptr) {
            node = node->next;
            count++;
        }
        return count;
    }

    ListNode *realSortList(ListNode *node, int size) {
        if (size == 0) {
            return nullptr;
        }
        else if (size == 1) {
            return node;
        }
        if (size == 2) {
            if(node->val <= node->next->val){
                return node;
            }else {
                ListNode *newHead = node->next;
                newHead->next = node;
                node->next = nullptr;
                return newHead;
            }
        }

        ListNode *headOne = node;
        // 平均分割链表到2个
        int count = 1;
        int sizeOne = size / 2;
        int sizeTwo = size - sizeOne;
        while (count++ < sizeOne) {
            node = node->next;
        }

        ListNode *headTwo = node->next;
        // 断尾
        node->next = nullptr;
        ListNode *orderOne = realSortList(headOne, sizeOne);
        ListNode *orderTwo = realSortList(headTwo, sizeTwo);
        return mergeKeepOrder(orderOne, orderTwo);
    }

    /**
     * 将已经排序的2个链表进行合并，保证合并后依然有序
     * @param oneNode
     * @param twoNode
     * @return
     */
    ListNode *mergeKeepOrder(ListNode *oneNode, ListNode *twoNode) {
        ListNode *head = new ListNode;
        ListNode *nowNode = head;
        while (oneNode != nullptr && twoNode != nullptr) {
            // 单次待加入的节点
            ListNode *tempNode;
            if (oneNode->val <= twoNode->val) {
                tempNode = oneNode;
                oneNode = oneNode->next;
            } else {
                tempNode = twoNode;
                twoNode = twoNode->next;
            }
            nowNode->next = tempNode;
            nowNode = nowNode->next;
        }

        nowNode->next = oneNode == nullptr ? twoNode : oneNode;

        return head->next;
    }

};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution solution;

    ListNode * three = new ListNode(3);
    ListNode * one = new ListNode(1, three);
    ListNode * two = new ListNode(2, one);
    ListNode * four = new ListNode(4, two);

    ListNode *pNode = solution.sortList(four);

    // 
    return 0;
}