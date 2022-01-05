//请你设计并实现一个满足 LRU (最近最少使用) 缓存 约束的数据结构。 
//
// 实现 LRUCache 类： 
//
// 
// 
// 
// LRUCache(int capacity) 以 正整数 作为容量 capacity 初始化 LRU 缓存 
// int get(int key) 如果关键字 key 存在于缓存中，则返回关键字的值，否则返回 -1 。 
// void put(int key, int value) 如果关键字 key 已经存在，则变更其数据值 value ；如果不存在，则向缓存中插入该组 
//key-value 。如果插入操作导致关键字数量超过 capacity ，则应该 逐出 最久未使用的关键字。 
// 
//
// 函数 get 和 put 必须以 O(1) 的平均时间复杂度运行。 
// 
// 
//
// 
//
// 示例： 
//
// 
//输入
//["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
//[[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
//输出
//[null, null, null, 1, null, -1, null, -1, 3, 4]
//
//解释
//LRUCache lRUCache = new LRUCache(2);
//lRUCache.put(1, 1); // 缓存是 {1=1}
//lRUCache.put(2, 2); // 缓存是 {1=1, 2=2}
//lRUCache.get(1);    // 返回 1
//lRUCache.put(3, 3); // 该操作会使得关键字 2 作废，缓存是 {1=1, 3=3}
//lRUCache.get(2);    // 返回 -1 (未找到)
//lRUCache.put(4, 4); // 该操作会使得关键字 1 作废，缓存是 {4=4, 3=3}
//lRUCache.get(1);    // 返回 -1 (未找到)
//lRUCache.get(3);    // 返回 3
//lRUCache.get(4);    // 返回 4
// 
//
// 
//
// 提示： 
//
// 
// 1 <= capacity <= 3000 
// 0 <= key <= 10000 
// 0 <= value <= 10⁵ 
// 最多调用 2 * 10⁵ 次 get 和 put 
// 
// Related Topics 设计 哈希表 链表 双向链表 👍 1824 👎 0


#include "iostream"
#include "cassert"
#include "vector"
#include "string"
#include "functional"
#include "unordered_map"
#include "list"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class LRUCache {
public:
    LRUCache(int capacity) {
        size = capacity;
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (map->count(key) == 0) {
            return -1;
        }

        ListNode *value = map->at(key);
        move2Head(value);
        return value->val;
    }

    void put(int key, int value) {
        // 已存在则更新
        if (map->count(key) != 0) {
            ListNode *&pNode = map->at(key);
            pNode->val = value;
            move2Head(pNode);
            return;
        }

        // 已满则先删除
        if (map->size() == size) {
            int k = removeTail();
            map->erase(k);
        }

        // 加入
        auto *node = new ListNode;
        node->key = key;
        node->val = value;
        move2Head(node);
        map->insert(unordered_map<int, ListNode *>::value_type(key, node));
    }

private:
    // 容量
    int size;

    // 双向链表节点
    struct ListNode {
        int key = -1;
        int val = -1;
        ListNode *prev = nullptr;
        ListNode *next = nullptr;
    };
    // 链表头
    ListNode *head = new ListNode;
    ListNode *tail = new ListNode;

    // hash map
    unordered_map<int, ListNode *> *map = new unordered_map<int, ListNode *>;

    void move2Head(ListNode *node) {
        ListNode *prevNode = node->prev;
        ListNode *nextNode = node->next;

        if (prevNode != nullptr && nextNode != nullptr) {
            prevNode->next = nextNode;
            nextNode->prev = prevNode;
        }

        ListNode *headNextNode = head->next;
        head->next = node;
        node->prev = head;

        node->next = headNextNode;
        headNextNode->prev = node;
    }

    int removeTail() {
        ListNode *node = tail->prev;

        ListNode *prevNode = node->prev;

        prevNode->next = tail;
        tail->prev = prevNode;

        return node->key;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    LRUCache solution(2);

    solution.put(2, 1);
    solution.put(1, 1);
    solution.put(2, 3);
    solution.put(4, 1);

    assert(solution.get(1) == -1);
    assert(solution.get(2) == 3);
    // 
    return 0;
}