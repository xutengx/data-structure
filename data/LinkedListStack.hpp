//
// Created by xuteng on 2021/4/7.
//

#ifndef DATA_STRUCTURE_LINKEDLISTSTACK_HPP
#define DATA_STRUCTURE_LINKEDLISTSTACK_HPP

using namespace std;

/**
 * 1）顺序栈的操作：入栈和出栈；
 * 2）采用模板的方法实现存储任意类型的数据
 */

template<class T> class LinkedListStack {
private:
    struct LinkedNode {
        T val = NULL;
        LinkedNode *next = nullptr;
    };
    LinkedNode *head;
    T vala;
public:
    LinkedListStack();

    ~LinkedListStack();

    // 入栈
    bool push(const T & data);

    // 出栈，并删除栈顶元素
    T pop();

    // 返回栈顶元素，不删除栈顶元素，栈顶指针不变
    T peek();

    static void test();
};

template<class T> LinkedListStack<T>::LinkedListStack() {
    head = new LinkedNode;
}

template<class T> LinkedListStack<T>::~LinkedListStack() {
    LinkedNode *pNodeTemp;
    LinkedNode *pNode = this->head;
    while (pNode->next != nullptr){
        pNodeTemp = pNode;
        pNode = pNode->next;
        delete pNodeTemp;
    }
    delete head;
    this->head = nullptr;
}

template<class T>
bool LinkedListStack<T>::push(const T &data) {
    auto *node = new LinkedNode;
    node->val = data;
    if(head->next != nullptr){
        node->next = head->next;
    }
    head->next = node;
    return true;
}

template<class T> T LinkedListStack<T>::pop() {
    LinkedNode *node;
    if(head->next != nullptr){
        node = head->next;
        head->next = head->next->next;
        return node->val;
    }
    return NULL;
}
template<class T> T LinkedListStack<T>::peek() {
    LinkedNode *node;
    if(head->next != nullptr){
        node = head->next;
        return node->val;
    }
    return NULL;
}

template<class T> void LinkedListStack<T>::test() {

}



#endif //DATA_STRUCTURE_LINKEDLISTSTACK_HPP
