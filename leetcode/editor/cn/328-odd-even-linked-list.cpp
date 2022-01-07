//给定一个单链表，把所有的奇数节点和偶数节点分别排在一起。请注意，这里的奇数节点和偶数节点指的是节点编号的奇偶性，而不是节点的值的奇偶性。 
//
// 请尝试使用原地算法完成。你的算法的空间复杂度应为 O(1)，时间复杂度应为 O(nodes)，nodes 为节点总数。 
//
// 示例 1: 
//
// 输入: 1->2->3->4->5->NULL
//输出: 1->3->5->2->4->NULL
// 
//
// 示例 2: 
//
// 输入: 2->1->3->5->6->4->7->NULL 
//输出: 2->3->6->7->1->5->4->NULL 
//
// 说明: 
//
// 
// 应当保持奇数节点和偶数节点的相对顺序。 
// 链表的第一个节点视为奇数节点，第二个节点视为偶数节点，以此类推。 
// 
// Related Topics 链表 👍 516 👎 0


#include "iostream"

#include "cassert"

#include "vector"

#include "string"

#include "functional"

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {
    }

    ListNode(int x) : val(x), next(nullptr) {
    }

    ListNode(int x, ListNode *next) : val(x), next(next) {
    }
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
    ListNode *oddEvenList(ListNode *head) {
        ListNode *theHead = new ListNode;
        ListNode *theNode = theHead;
        ListNode *otherHead = new ListNode;
        ListNode *otherNode = otherHead;
        bool flag = true;
        while (head != nullptr) {
            if (flag) {
                flag = false;
                theNode->next = head;
                theNode = theNode->next;
            }
            else {
                flag = true;
                otherNode->next = head;
                otherNode = otherNode->next;
            }
            head = head->next;
        }
        theNode->next = otherHead->next;
        // 剔除野指针
        otherNode->next = nullptr;
        return theHead->next;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution solution;
    
    ListNode *three = new ListNode(3);
    ListNode *one = new ListNode(1, three);
    ListNode *two = new ListNode(2, one);
    ListNode *four = new ListNode(4, two);

    ListNode *pNode = solution.oddEvenList(four);

    return 0;
}