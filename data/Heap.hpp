//
// Created by xuteng on 2021/4/22.
//

#ifndef DATA_STRUCTURE_HEAP_HPP
#define DATA_STRUCTURE_HEAP_HPP

#include "functional"

/**
 * 堆(大头堆 or 小头堆)
 * 堆是一个完全二叉树；
 * 堆中每一个节点的值都必须大于等于（或小于等于）其子树中每个节点的值。
 */
class Heap {
private:
    struct Node {
        int key = 444;
        string val;
    };
    /**
     * 因为对是完全二叉树, 所以特别适合使用数组存储
     *
     * 不使用下标为 0 的位置, 方便计算
     * 数组中下标为 i 的节点的左子节点，就是下标为 i∗2 的节点，右子节点就是下标为 i∗2+1 的节点，父节点就是下标为 2i 的节点。
     */
    Node **data;
    bool bigHeap = true;
    int maxSize;
    int count = 0;

    static void swap(Node **father, Node **node) {
        Node * temp = *father;
        *father = *node;
        *node = temp;

//        int tInt = father->key;
//        string tString = father->val;
//        father->key = node->key;
//        father->val = node->val;
//        node->key = tInt;
//        node->val = tString;
    }

public:
    Heap() : Heap(true, 10) {}

    explicit Heap(bool isBigHeap, int maxSize) {
        bigHeap = isBigHeap;
        this->maxSize = maxSize;
        data = new Node *[maxSize + 2];       // 0 不使用所以加一; 先加在判断是否满,所以容量再加一
    }

    ~Heap() {
        // todo
    }

    void put(int key, const string &value) {
        // 新的节点
        Node *newNode = new Node;
        newNode->key = key;
        newNode->val = value;
        int newIndex = count + 1;
        data[newIndex] = newNode;

        // 父节点
        int fatherIndex = newIndex / 2;
        Node *fatherNode = data[fatherIndex];

        // 大头堆
        while (bigHeap && fatherIndex != 0 && fatherNode->key < newNode->key) {
            // 值交换
            swap(&fatherNode, &newNode);
            // 当前节点的 idx 切换到父节点的 idx
            newIndex = fatherIndex;
            // 当前节点
            newNode = data[newIndex];
            // 父节点
            fatherNode = data[newIndex / 2];
        }

        // 小头堆
        while (!bigHeap && fatherIndex != 0 && (fatherNode->key > newNode->key)) {
            swap(&fatherNode, &newNode);
            newIndex = fatherIndex;
            newNode = data[newIndex];
            fatherNode = data[newIndex / 2];
        }

        // 未满的情况才增加计数, 满了就不变
        if (count != maxSize) {
            count++;
        }
    }

    Node *pop() {
        if (count == 0) {
            return nullptr;
        }

        Node *pNode = data[1];
        swap(&data[1], &data[count]);

        int parent = 1;
        int left, right, max;
        count--;

        while (true) {
            left = parent * 2;
            right = left + 1;
            max = parent;
            if (left <= count && data[max]->key < data[left]->key)
                max = left;
            if (right <= count && data[max]->key < data[right]->key)
                max = right;
            if (max == parent)
                break;
            swap(&data[max], &data[parent]);
            parent = max;
        }

        return pNode;

    }

    void dump() {
        cout << "dump heap " << bigHeap << "\n";
        for (int i = 1; i <= count; i++) {
            cout << "data[" << i << "], key = " << data[i]->key << " , val = " << data[i]->val << " .\n";
        }
        cout << "\n";
    }

    static void test() {
        Heap *pHeap = new Heap(true, 4);
        pHeap->put(999, "999");
        pHeap->put(9, "9");
        pHeap->put(99, "99");
        pHeap->put(1, "1");
        pHeap->dump();
        assert(pHeap->pop()->val == "999");
        pHeap->dump();
        assert(pHeap->pop()->val == "99");
        pHeap->dump();
        assert(pHeap->pop()->val == "9");
        pHeap->dump();
        assert(pHeap->pop()->val == "1");
    }
};

#endif //DATA_STRUCTURE_HEAP_HPP
