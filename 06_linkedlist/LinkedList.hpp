//
// Created by xuteng on 2021/4/6.
//

#ifndef DATA_STRUCTURE_LINKEDLIST_HPP
#define DATA_STRUCTURE_LINKEDLIST_HPP

// 链表类
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
    // 链表总大小
    int size;
    // 链表当前长度
    int length;
    // 链表头节点指针
    ListNode *head;
    // 查找末节点
    ListNode* FindLastElem();
public:
    // 无参构造
    LinkedList();
    // 初始化大小的构造
    explicit LinkedList(int size);
    // 析构函数
    ~LinkedList();
    // 头部插入
    bool InsertElemAtFront(int elemVal);
    // 尾部插入
    bool InsertElemAtBack(int elemVal);
    // 查找节点
    ListNode* FindElem(int elemVal);
    // 删除指定节点
    bool DeleteElem(ListNode *elem);
    // 弹出末尾节点
    int DeleteLastElem();
    // 如果字符串是通过单链表来存储的，那该如何来判断是一个回文串呢？
    bool CheckPalindromeList();
    // 打印所有
    void PrintList();
    // 测试
    static void Test();
};

// 无参构造函数调用有参构造函数
LinkedList::LinkedList() : LinkedList(10) {}

LinkedList::LinkedList(int size) {
    this->size = size;
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
    // 声明末节点, 并找到真正的它
    ListNode *end = FindLastElem();
    end->next = node;
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

bool LinkedList::CheckPalindromeList() {
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

    ListNode *start = mid;
    ListNode *prev = nullptr;
    ListNode *temp = start;
    while (start->next != nullptr){
        prev = start;
        temp->next = prev;
        start = start->next;
        temp = prev;
    }

    return false;

}

void LinkedList::Test(){
    auto linkedList = new LinkedList();
    linkedList->PrintList();
    linkedList->InsertElemAtBack(1);
    linkedList->InsertElemAtBack(2);
    linkedList->InsertElemAtBack(3);
    linkedList->InsertElemAtBack(4);
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
    linkedList->InsertElemAtBack(4);
    linkedList->InsertElemAtBack(5);
    linkedList->InsertElemAtFront(1);
    linkedList->PrintList();
    linkedList->CheckPalindromeList();


}

#endif //DATA_STRUCTURE_LINKEDLIST_HPP
