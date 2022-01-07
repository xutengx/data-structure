//对链表进行插入排序。 
//
// 
//插入排序的动画演示如上。从第一个元素开始，该链表可以被认为已经部分排序（用黑色表示）。 
//每次迭代时，从输入数据中移除一个元素（用红色表示），并原地将其插入到已排好序的链表中。 
//
// 
//
// 插入排序算法： 
//
// 
// 插入排序是迭代的，每次只移动一个元素，直到所有元素可以形成一个有序的输出列表。 
// 每次迭代中，插入排序只从输入数据中移除一个待排序的元素，找到它在序列中适当的位置，并将其插入。 
// 重复直到所有输入数据插入完为止。 
// 
//
// 
//
// 示例 1： 
//
// 输入: 4->2->1->3
//输出: 1->2->3->4
// 
//
// 示例 2： 
//
// 输入: -1->5->3->4->0
//输出: -1->0->3->4->5
// 
// Related Topics 链表 排序 👍 467 👎 0


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
    ListNode *insertionSortList(ListNode *head) {
        if (head == nullptr) {
            return nullptr;
        }
        auto *theHead = new ListNode(INT32_MIN);
        theHead->next = head;

        ListNode *pNode = theHead;
        while (pNode != nullptr) {
            ListNode *nodeTemp = pNode->next;
            // 前面的比后面的大，当然是要排序啦
            if (nodeTemp != nullptr && (pNode->val > nodeTemp->val)) {
                ListNode *pListNode = removeNextNode(pNode);
                insertByOrder(theHead, pListNode);
                continue;
            }
            pNode = pNode->next;
        }

        return theHead->next;
    }

private:
    /**
     * 移除并返回下一个节点，返回的节点的next仍然有效
     * @param node
     * @return
     */
    ListNode *removeNextNode(ListNode *node) {
        ListNode *pNode = node->next;
        if (pNode != nullptr) {
            node->next = pNode->next;
        }
        return pNode;
    }

    /**
     * 将node按顺序插入到链表
     * @param headNode
     * @param node
     */
    void insertByOrder(ListNode *headNode, ListNode *node) {
        bool flag = false;
        ListNode *prevNode = nullptr;
        while (headNode->next != nullptr) {
            // 当前节点小于目标节点，则判断下一个
            if (headNode->val < node->val) {
                prevNode = headNode;
                headNode = headNode->next;
            } else {
                flag = true;
                prevNode->next = node;
                node->next = headNode;
//                ListNode *pNode = headNode->next;
//                headNode->next = node;
//                headNode->next->next = pNode;
                break;
            }
        }
        // headNode 是最后的节点
        if (!flag) {
            if(prevNode != nullptr){
                prevNode->next = node;
                node->next = headNode;
            } else{
                headNode->next = node;
                node->next = nullptr;
            }
        }
    }

};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution solution;

    ListNode *three = new ListNode(3);
    ListNode *one = new ListNode(1, three);
    ListNode *two = new ListNode(2, one);
    ListNode *four = new ListNode(4, two);

    ListNode *pNode = solution.insertionSortList(four);

    // 
    return 0;
}