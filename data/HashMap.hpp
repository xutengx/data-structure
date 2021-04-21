//
// Created by xuteng on 2021/4/21.
//

#ifndef DATA_STRUCTURE_HASHMAP_HPP
#define DATA_STRUCTURE_HASHMAP_HPP

// 默认hash桶大小
#define DEFAULT_INITIAL_CAPACITY 16
// 装载因子
#define DEFAULT_LOAD_FACTOR 0.75f

class HashMap {
private:
    int tableMaxSize;
    int tableUsedSize = 0;
    // hash冲突使用链表法解决
    struct LinkedNode {
        string key;
        string value;
        LinkedNode *next = nullptr;
    };
    LinkedNode *table;

    /**
     * 计算key的hash值
     * @param key
     * @return
     */
    static unsigned int hash(const string *str1, int tableSize) {
        // string 转化为 char
        const char *str = str1->data();
        unsigned int hashValue = 0;
        unsigned int seed = 131;
        while (*str) {
            hashValue = hashValue * seed + *str++;
        }
        unsigned int i = hashValue & (0x7FFFFFFF);
        // 在原hash桶中的位置
        unsigned int index = (tableSize - 1) & i;
        return index;
    }

    void resize() {
        if ((tableMaxSize * DEFAULT_LOAD_FACTOR) > tableUsedSize)
            return;

        int newTableMaxSize = tableMaxSize << 1;
        auto *newTable = new LinkedNode[newTableMaxSize];

        for (int i = 0; i < tableMaxSize; i++) {
            LinkedNode list = table[i];

            // 迁移
            while (list.next != nullptr) {
                // 在新hash桶中的位置
                unsigned int newIndex = hash(&list.next->key, newTableMaxSize);
                LinkedNode &newList = newTable[newIndex];

                linkedNodePut(&newList, list.next->key, list.next->value);
                LinkedNode *tempNode = list.next;
//                delete node;
                list = *tempNode;
            }
        }
        // 设置属性
        tableMaxSize = newTableMaxSize;
        delete[] table;
        table = newTable;
    }

    static void linkedNodePut(LinkedNode *oTable, const string &key, const string &value) {
        // 构造节点
        auto *pNode = new LinkedNode();
        pNode->key = key;
        pNode->value = value;
        // 将节点加入
        LinkedNode *temp = oTable;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = pNode;
    }

    LinkedNode *linkedNodeGet(const string &key) {
        // 在原hash桶中的位置
        unsigned int index = hash(&key, tableMaxSize);

        LinkedNode *node = &table[index];
        while (node->next != nullptr) {
            LinkedNode *tempNode = node->next;
            if (key == tempNode->key) {
                return tempNode;
            }
        }
        return nullptr;
    }

public:
    HashMap() : HashMap(DEFAULT_INITIAL_CAPACITY) {};

    explicit HashMap(int size) {
        tableMaxSize = size;
        table = new LinkedNode[size];
    }

    virtual ~HashMap() {
        // todo
    }

    bool put(const string &key, const string &value) {
        // 扩容
        resize();
        // 查找node
        LinkedNode *pNode = linkedNodeGet(key);
        if (pNode != nullptr) {
            // 更改值
            pNode->value = value;
        } else {
            // 在原hash桶中的位置
            unsigned int index = hash(&key, tableMaxSize);
            // 链表后面直接追加
            linkedNodePut(&table[index], key, value);
        }
        tableUsedSize++;
        return true;
    }

    string const *get(const string &key) {
        LinkedNode *pNode = linkedNodeGet(key);
        if (pNode != nullptr) {
            return &pNode->value;
        }
        return nullptr;
    }

    void dump() {

    }

    static void test();
};

void HashMap::test() {
    auto *pMap = new HashMap(4);
    pMap->put("1key", "1value");
    pMap->put("2key", "2value");
    pMap->put("3key", "3value");
    pMap->put("4key", "4value");
    pMap->put("5key", "5value");

    const string *pString = pMap->get("3key");
    string basicString = *pString;

    assert(*(pMap->get("3key")) == "3value");
    assert(*(pMap->get("5key")) == "5value");
    pMap->put("5key", "5value222");
    assert(*(pMap->get("5key")) == "5value222");
}

#endif //DATA_STRUCTURE_HASHMAP_HPP
