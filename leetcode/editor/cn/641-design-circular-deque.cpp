//设计实现双端队列。 
//你的实现需要支持以下操作： 
//
// 
// MyCircularDeque(k)：构造函数,双端队列的大小为k。 
// insertFront()：将一个元素添加到双端队列头部。 如果操作成功返回 true。 
// insertLast()：将一个元素添加到双端队列尾部。如果操作成功返回 true。 
// deleteFront()：从双端队列头部删除一个元素。 如果操作成功返回 true。 
// deleteLast()：从双端队列尾部删除一个元素。如果操作成功返回 true。 
// getFront()：从双端队列头部获得一个元素。如果双端队列为空，返回 -1。 
// getRear()：获得双端队列的最后一个元素。 如果双端队列为空，返回 -1。 
// isEmpty()：检查双端队列是否为空。 
// isFull()：检查双端队列是否满了。 
// 
//
// 示例： 
//
// MyCircularDeque circularDeque = new MycircularDeque(3); // 设置容量大小为3
//circularDeque.insertLast(1);			        // 返回 true
//circularDeque.insertLast(2);			        // 返回 true
//circularDeque.insertFront(3);			        // 返回 true
//circularDeque.insertFront(4);			        // 已经满了，返回 false
//circularDeque.getRear();  				// 返回 2
//circularDeque.isFull();				        // 返回 true
//circularDeque.deleteLast();			        // 返回 true
//circularDeque.insertFront(4);			        // 返回 true
//circularDeque.getFront();				// 返回 4
//  
//
// 
//
// 提示： 
//
// 
// 所有值的范围为 [1, 1000] 
// 操作次数的范围为 [1, 1000] 
// 请不要使用内置的双端队列库。 
// 
// Related Topics 设计 队列 
// 👍 79 👎 0


#include "functional"
#include "vector"
#include "assert.h"
#include "string"
#include "iostream"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class MyCircularDeque {
private:
    int maxSize = 0;
    int size = 0;

    struct ListNode {
        int val = -1;
        ListNode *front = nullptr;
        ListNode *next = nullptr;

        explicit ListNode(int k) {
            val = k;
        }
    };

    ListNode *head = new ListNode(-1);
    ListNode *tail = nullptr;
public:
    /** Initialize your data structure here. Set the size of the deque to be k. */
    MyCircularDeque(int k) {
        maxSize = k;
    }

    /** Adds an item at the front of Deque. Return true if the operation is successful. */
    bool insertFront(int value) {
        if (size == maxSize) {
            return false;
        }
        ListNode *pNode = head->next;
        head->next = new ListNode(value);
        head->next->front = head;
        head->next->next = pNode;
        if (pNode == nullptr) {
            tail = head->next;
        } else {
            pNode->front = head->next;
        }
        size++;
        return true;
    }

    /** Adds an item at the rear of Deque. Return true if the operation is successful. */
    bool insertLast(int value) {
        if (size == maxSize) {
            return false;
        }
        if (tail != nullptr) {
            tail->next = new ListNode(value);
            tail->next->front = tail;
            tail = tail->next;
        } else {
            return insertFront(value);
        }
        size++;
        return true;
    }

    /** Deletes an item from the front of Deque. Return true if the operation is successful. */
    bool deleteFront() {
        if (size == 0) {
            return false;
        }
        ListNode *pNode = head->next;
        head->next = head->next->next;
        if (head->next != nullptr) {
            head->next->front = head;
        }
//        delete pNode;
        size--;
        if(size == 0){
            tail = nullptr;
        }
        return true;
    }

    /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
    bool deleteLast() {
        if (size == 0) {
            return false;
        }
        ListNode *pNode = tail;
        tail = tail->front;
        tail->next = nullptr;
//        delete pNode;
        size--;
        if(size == 0){
            tail = nullptr;
        }
        return true;
    }

    /** Get the front item from the deque. */
    int getFront() {
        if (size == 0) {
            return -1;
        }
        return head->next->val;
    }

    /** Get the last item from the deque. */
    int getRear() {
        if (size == 0) {
            return -1;
        }
        return tail->val;
    }

    /** Checks whether the circular deque is empty or not. */
    bool isEmpty() {
        return size == 0;
    }

    /** Checks whether the circular deque is full or not. */
    bool isFull() {
        return size == maxSize;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    MyCircularDeque *obj = new MyCircularDeque(52);
    bool param_1 = obj->insertFront(80);
    int param_5 = obj->getFront();
    bool param_x = obj->insertFront(27);
    int param_ddd = obj->getFront();
    bool param_4 = obj->deleteLast();
    bool param_xxx = obj->insertFront(60);
    bool param_xcxx = obj->insertFront(81);
    int param_6 = obj->getRear();
    int param_dbdd = obj->getFront();
    int param_6q = obj->getRear();
    int param_62 = obj->getRear();
    bool b = obj->insertLast(46);

    bool front = obj->deleteFront();
    int i = obj->getFront();
    bool b1 = obj->insertLast(98);
    int param_6q1 = obj->getRear();
    bool b11 = obj->insertLast(11);
    bool front1 = obj->deleteFront();
    bool param_xcxx1 = obj->insertFront(51);
    bool par = obj->isFull();

    obj->deleteFront();
    obj->deleteFront();
    obj->deleteFront();
    obj->deleteFront();
    obj->deleteFront();
    obj->deleteFront();
    obj->deleteFront();

//    obj->deleteLast();
//    obj->deleteLast();
//    obj->deleteLast();
//    obj->deleteLast();
//    obj->deleteLast();
//    obj->deleteLast();
//    obj->deleteLast();
//    obj->deleteLast();

//    测试用例:["MyCircularDeque","insertFront","getFront","insertFront","getFront","deleteLast","insertFront","insertFront","getRear","getFront","getRear","getRear","insertLast",
//    "deleteFront","getFront","insertLast","getRear","insertLast","deleteFront","insertFront","isFull","getRear","deleteLast","insertLast","getRear","getFront","getFront","insertLast","insertFront","deleteFront","getRear","insertLast","deleteFront","insertFront","insertFront","getRear","getFront","insertFront","insertLast","getRear","getFront","insertFront","insertFront","insertLast","insertLast","getRear","isEmpty","deleteFront","getRear","getRear","getRear","insertLast","getFront","getFront","deleteLast","deleteLast","insertLast","getRear","getRear","insertLast","insertLast","insertFront","getFront","getRear","getFront","insertFront","insertFront","deleteFront","isEmpty","getFront","deleteFront","isFull","getFront","getRear","insertLast","getFront","insertLast","getRear","insertLast","insertFront","getRear","getFront","getFront","deleteLast","deleteLast","insertLast","getRear","getRear","getFront","deleteLast","isFull","insertLast","insertLast","insertFront","getFront","insertFront","isFull","getRear","insertFront","deleteLast","insertLast","insertLast"]
//    [[52],[80],[],[27],[],[],[60],[81],[],[],[],[],[46],
//    [],[],[98],[],[11],[],[51],[],[],[],[28],[],[],[],[28],[69],[],[],[11],[],[25],[74],[],[],[48],[7],[],[],[65],[59],[23],[32],[],[],[],[],[],[],[84],[],[],[],[],[64],[],[],[17],[34],[46],[],[],[],[6],[20],[],[],[],[],[],[],[],[34],[],[66],[],[54],[34],[],[],[],[],[],[43],[],[],[],[],[],[21],[93],[79],[],[8],[],[],[78],[],[7],[67]]
//    测试结果:[null,true,80,true,27,true,true,true,80,81,80,80,true,true,60,true,98,true,true,true,false,11,true,true,28,51,51,true,true,true,28,true,true,true,true,11,74,true,true,7,48,true,true,true,true,32,false,true,32,32,32,true,65,65,true,true,true,64,64,true,true,true,46,34,46,true,true,true,false,6,true,false,46,34,true,46,true,66,true,true,54,34,34,true,true,true,43,43,34,true,false,true,true,true,79,true,false,93,true,true,true,true]
//    期望结果:[null,true,80,true,27,true,true,true,27,81,27,27,true,true,60,true,98,true,true,true,false,11,true,true,28,51,51,true,true,true,28,true,true,true,true,11,74,true,true,7,48,true,true,true,true,32,false,true,32,32,32,true,65,65,true,true,true,64,64,true,true,true,46,34,46,true,true,true,false,6,true,false,46,34,true,46,true,66,true,true,54,34,34,true,true,true,43,43,34,true,false,true,true,true,79,true,false,93,true,true,true,true]

    return 0;
}