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
        Node(T value){
            val = value;
            next = nullptr;
        }
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
};

template<class T>
LinkedListQueue<T>::LinkedListQueue() {
    Node *pHead = new Node(NULL);
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
    return true;
}

template<class T>
T LinkedListQueue<T>::pop() {
    if(head->next != nullptr){
        Node *pNode = head->next;
        head->next = (head->next->next != nullptr) ? head->next->next : nullptr;
        return pNode;
    }
    return nullptr;
}

template<class T>
T LinkedListQueue<T>::peek() {
    if(head->next != nullptr){
        return head->next;
    }
    return nullptr;
}


#endif //DATA_STRUCTURE_LINKEDLISTQUEUE_HPP
