//
// Created by xuteng on 2021/4/9.
//

#ifndef DATA_STRUCTURE_LINKEDLISTQUEUE_HPP
#define DATA_STRUCTURE_LINKEDLISTQUEUE_HPP

/**
 * 基于链表的队列，无限容量，
 * @tparam T
 */
template<class T>
class LinkedListQueue {
private:
    struct Node{
        T val;
        Node *next;
        Node(){
            next = nullptr;
        };
        explicit Node(T value){
            val = value;
            next = nullptr;
        };
    };
    Node *head; // 头部
    Node *tail; // 尾部

public:
    LinkedListQueue();
    ~LinkedListQueue();
    // 尾部插入
    bool push(T value);
    // 头部弹出
    T pop();
    // 头部返回，但不弹出
    T peek();
    // 打印
    void dump();
    // 测试
    static void test();
};

template<class T>
LinkedListQueue<T>::LinkedListQueue() {
    Node *pHead = new Node();
    head = pHead;
    tail = nullptr;
}

template<class T>
LinkedListQueue<T>::~LinkedListQueue() {
    Node *pTempNode;
    while (head->next != nullptr){
        pTempNode = head->next;
        if(pTempNode->next != nullptr){
            head->next = pTempNode->next;
        }
        delete pTempNode;
    }
    delete head;
    head = nullptr;
    tail = nullptr;
}

template<class T>
bool LinkedListQueue<T>::push(T value) {
    Node *pNode = new Node(value);
    if(head->next != nullptr){
        tail->next = pNode;
        tail = pNode;
    } else{
        head->next = tail = pNode;
    }
    cout << "push : " << value << "\n";
    return true;
}

template<class T>
T LinkedListQueue<T>::pop() {
    if(head->next != nullptr){
        Node *pNode = head->next;
        head->next = (head->next->next != nullptr) ? head->next->next : nullptr;
        cout << "pop : " << pNode->val << "\n";
        return pNode->val;
    }
    return -1;
}

template<class T>
T LinkedListQueue<T>::peek() {
    if(head->next != nullptr){
        cout << "peek : " << head->next->val << "\n";
        return head->next->val;
    }
    return -1;
}

template<class T>
void LinkedListQueue<T>::dump() {
    printf("dump data[");

    Node *pNode = head;
    while (pNode->next != nullptr){
        cout << pNode->next->val << " ";
        pNode = pNode->next;
    }
    cout << "]\n";
}

template<class T>
void LinkedListQueue<T>::test() {
    cout << "LinkedListQueue test start ! \n";

    auto *pQueue = new LinkedListQueue<int>();
    pQueue->push(0);
    pQueue->push(1);
    pQueue->push(2);
    pQueue->push(3);
    pQueue->push(4);
    pQueue->dump();
    pQueue->peek();
    pQueue->pop();
    pQueue->dump();
    pQueue->push(5);
    pQueue->dump();
    pQueue->push(6);
    pQueue->dump();
    pQueue->push(7);
    pQueue->dump();
    pQueue->push(8);
    pQueue->dump();
    pQueue->push(9);
    pQueue->dump();

    pQueue->pop();
    pQueue->pop();   pQueue->pop();
    pQueue->pop();   pQueue->pop();
    pQueue->pop();   pQueue->pop();
    pQueue->pop();   pQueue->pop();
    pQueue->pop();
    pQueue->dump();

    pQueue->push(9);
    pQueue->push(8);
    pQueue->push(7);
    pQueue->dump();
}


#endif //DATA_STRUCTURE_LINKEDLISTQUEUE_HPP
