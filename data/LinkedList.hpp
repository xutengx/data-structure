//
// Created by xuteng on 2021/4/6.
//

#ifndef DATA_STRUCTURE_LINKEDLIST_HPP
#define DATA_STRUCTURE_LINKEDLIST_HPP

#include <iostream>

using namespace std;

/**
 * 链表实现 LRU 缓存。 有序单链表 由新到旧排序，链尾是越早之前访问的，每当有新元素，先遍历数组是否已存在该元素。
 * 存在时则删除原位置元素，并将之放链表头部。 未存在，分以下两种：
 * 1.缓存未满，直接将该结点插入链表头部。
 * 2.缓存已满，删除链表尾结点，将新结点插入链表头部。
 */
// 单链表类
class LinkedList{
public:
    // 链表节点类
    class ListNode{
    public:
        int val;
        ListNode *next;
        // 无参构造函数调用有参构造函数
        ListNode() : ListNode(-1) {}
        explicit ListNode(int value){
            this->val = value;
            this->next = nullptr;
        }
    };
private:
    // 链表当前长度
    int length;
    // 链表头节点指针
    ListNode *head;
    // 查找末节点
    ListNode* FindLastElem();
public:
    // 无参构造
    LinkedList();
    // 析构函数
    ~LinkedList();
    // 头部插入
    bool InsertElemAtFront(int elemVal);
    // 尾部插入
    bool InsertElemAtBack(int elemVal);
    // 尾部插入
    bool InsertElemAtBack(ListNode *elem);
    // 查找节点
    ListNode* FindElem(int elemVal);
    // 删除指定节点
    bool DeleteElem(ListNode *elem);
    // 删除链表倒数第 n 个结点
    bool DeleteElem(int n);
    // 弹出末尾节点
    int DeleteLastElem();
    // 如果字符串是通过单链表来存储的，那该如何来判断是一个回文串呢？
    bool CheckPalindromeList();
    // 打印所有
    void PrintList();
    // 测试
    static void Test();
    // 反转单向链表
    static ListNode * FlipLinkedList(ListNode *elem);
    // 链表中环的检测
    static bool CheckCircle(ListNode *elem);
};

LinkedList::LinkedList() {
    this->length = 0;
    this->head = new ListNode();
}

LinkedList::~LinkedList() {
    ListNode *p, *q;
    p = this -> head;
    while(p -> next != nullptr) {
        q = p -> next;
        p -> next = p -> next -> next;
        delete q;
    }
    delete head;
    this -> head = nullptr;
    this -> length = 0;
}

bool LinkedList::InsertElemAtFront(int elemVal){
    // 新建节点
    auto *node = new ListNode();
    node->val = elemVal;
    // 节点加入
    node->next = this->head->next;
    this->head->next = node;
    this->length++;
    return true;
}

bool LinkedList::InsertElemAtBack(int elemVal) {
    // 新建节点
    auto *node = new ListNode(elemVal);
    return InsertElemAtBack(node);
}

bool LinkedList::InsertElemAtBack(ListNode *elem) {
    // 声明末节点, 并找到真正的它
    ListNode *end = FindLastElem();
    end->next = elem;
    this->length++;
    return true;
}

int LinkedList::DeleteLastElem() {
    ListNode *prev, *end;
    // 找到倒数第2个节点
    for(prev = this->head; prev->next != nullptr && prev->next->next != nullptr; prev = prev->next);
    // 如果不存在任何一个节点
    if(prev->next == nullptr){
       return this->head->val;
    }
    end = prev->next;
    prev->next = nullptr;
    int value = end->val;
    delete end;
    this->length--;
    return value;
}

LinkedList::ListNode * LinkedList::FindElem(int elemVal) {
    ListNode *elem;
    for (elem = this->head; elem->next != nullptr; elem = elem->next){
        if(elem->val == elemVal){
            return elem;
        }
    }
    return nullptr;
}

LinkedList::ListNode * LinkedList::FindLastElem() {
    auto *end = this->head;
    while (end->next != nullptr){
        end = end->next;
    }
    return end;
}

void LinkedList::PrintList() {
    printf("List(%d): ", length);
    if(length != 0){
        ListNode *elem;
        for(elem = this->head->next; elem->next != nullptr; elem = elem->next){
            printf("%d, ",elem->val);
        }
        printf("%d",elem->val);
    }
    printf("\n");
}

bool LinkedList::DeleteElem(ListNode *elem){
    ListNode *prev, *next;
    for(prev = this->head; prev->next != elem && prev->next != nullptr; prev = prev->next);
    next = elem->next;
    prev->next = next;
    delete elem;
    this->length--;
    return true;
}

bool LinkedList::DeleteElem(int n) {
    ListNode *fast, *slow;
    fast = slow = this->head;
    while (fast->next != nullptr){
        fast = fast->next;
        slow = slow->next;
        while (n-- > 0){
            if(fast->next != nullptr){
                fast = fast->next;
            }else{
                return false;
            }
        }
    }
    if(slow->next != nullptr){
        slow->next = slow->next->next;
        length--;
    }
    return true;
}

/**
 * 不额外占用空间
 * @return
 */
bool LinkedList::CheckPalindromeList() {
    PrintList();

    // 找到链表中点
    ListNode *fast, *slow, *mid;
    slow = fast = this->head;
    mid = nullptr;
    while (fast->next != nullptr){
        fast = fast->next;
        mid = slow->next;
        if(fast->next != nullptr){
            fast = fast->next;
            slow = slow->next;
        }
    }
    if(mid == nullptr){
        return false;
    }

    // 反转 mid 与其之后的链表
    ListNode *start = FlipLinkedList(mid);

    ListNode *node = this->head->next;
    ListNode *startNode = start;
    bool palindrome = true;

    while (node != nullptr && startNode != nullptr ){
        if(node->val != startNode->val){
            palindrome = false;
            break;
        }
        node = node->next;
        startNode = startNode->next;
    }
    // 是否回文
    printf("Is palindrome ? %d \n", palindrome);

    // 反转 start 与其之后的链表
    // 用于还原
    FlipLinkedList(start);

    return palindrome;

}

LinkedList::ListNode * LinkedList::FlipLinkedList(ListNode *elem) {
    // 开始
    ListNode *start = elem;
    // 前一个节点
    ListNode *prev1 = nullptr;
    // 前二个节点
    ListNode *prev2 = nullptr;

    while (start->next != nullptr){
        prev2 = prev1;
        prev1 = start;
        start = start->next; // 后移
        prev1->next = prev2;
        // 没更多节点了
        if(start->next == nullptr){
            start->next = prev1;
            break;
        }
    }
    return start;
}

bool LinkedList::CheckCircle(ListNode *elem) {
    bool flog = false;
    ListNode *fast, *slow;
    fast = slow = elem;
    while (fast->next != nullptr){
        fast = fast->next;
        slow = slow->next;
        if(fast->next != nullptr){
            fast = fast->next;
        }
        if(fast == slow){
            flog = true;
            break;
        }
    }
    printf("Is circle ? %d \n", flog);
    return flog;
}

void LinkedList::Test(){
    auto linkedList = new LinkedList();
    linkedList->PrintList();
    linkedList->InsertElemAtBack(1);
    linkedList->CheckPalindromeList();
    linkedList->InsertElemAtBack(2);
    linkedList->CheckPalindromeList();
    linkedList->InsertElemAtBack(1);
    linkedList->CheckPalindromeList();
    linkedList->InsertElemAtBack(4);
    linkedList->CheckPalindromeList();
    linkedList->InsertElemAtBack(5);
    linkedList->PrintList();
    linkedList->InsertElemAtFront(0);
    linkedList->PrintList();
    int elem = linkedList->DeleteLastElem();
    linkedList->PrintList();
    ListNode *node = linkedList->FindElem(0);
    linkedList->DeleteElem(node);
    linkedList->PrintList();
    linkedList->DeleteLastElem();
    linkedList->DeleteLastElem();
    linkedList->DeleteLastElem();
    linkedList->DeleteLastElem();
    linkedList->PrintList();
    linkedList->DeleteLastElem();
    linkedList->PrintList();
    linkedList->InsertElemAtBack(2);
    linkedList->InsertElemAtBack(3);
    linkedList->InsertElemAtBack(2);
    linkedList->InsertElemAtBack(1);
    linkedList->InsertElemAtFront(1);
    linkedList->PrintList();
    linkedList->CheckPalindromeList();
    linkedList->PrintList();

    linkedList->DeleteElem(3);
    linkedList->PrintList();

    // 手动成环
    auto *first = linkedList->FindElem(1);
    auto *node2 = new ListNode(9);
    node2->next = first;
    LinkedList::CheckCircle(first);
    linkedList->InsertElemAtBack(node2);
    LinkedList::CheckCircle(first);

}

#endif //DATA_STRUCTURE_LINKEDLIST_HPP
