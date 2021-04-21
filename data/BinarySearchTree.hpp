//
// Created by xuteng on 2021/4/21.
//

#ifndef DATA_STRUCTURE_BINARYSEARCHTREE_HPP
#define DATA_STRUCTURE_BINARYSEARCHTREE_HPP

/**
 * 二叉查找树
 * 二叉树: 每个节点最多有两个“叉”，也就是两个子节点，分别是左子节点和右子节点。
 * 二叉查找树: 二叉查找树要求，在树中的任意一个节点，其左子树中的每个节点的值，都要小于这个节点的值，而右子树节点的值都大于这个节点的值。
 */
class BinarySearchTree {
private:
    struct Node {
        Node *left = nullptr;
        Node *right = nullptr;
        int key = {};
        string value = {};
    };
    Node *root = nullptr;


    static void put(Node *node, int key, const string &val) {
        if (node == nullptr) {
            node = new Node;
            node->key = key;
            node->value = val;
            return;
        }

        if (node->key == key) {
            node->value = val;
        } else if (node->key > key) {
            put(node->left, key, val);
        } else {
            put(node->right, key, val);
        }
    }

    static Node *find(Node *node, int key) {
        if (node == nullptr) {
            return nullptr;
        }
        if (node->key == key) {
            return node;
        } else if (node->key > key) {
            return find(node->left, key);
        } else {
            return find(node->right, key);
        }
    }

    static Node *findBiggest(Node *node) {
        if (node == nullptr) {
            return nullptr;
        }
        if (node->right != nullptr) {
            return findBiggest(node->right);
        } else {
            return node;
        }
    }

    static Node *findSmallest(Node *node) {
        if (node == nullptr) {
            return nullptr;
        }
        if (node->left != nullptr) {
            return findSmallest(node->left);
        } else {
            return node;
        }
    }

    /**
     * 二叉查找树删除操作就比较复杂了 。针对要删除节点的子节点个数的不同，我们需要分三种情况来处理。
     * 第一种情况是，如果要删除的节点没有子节点，我们只需要直接将父节点中，指向要删除节点的指针置为 null。
     * 第二种情况是，如果要删除的节点只有一个子节点（只有左子节点或者右子节点），我们只需要更新父节点中，指向要删除节点的指针，让它指向要删除节点的子节点就可以了
     * 第三种情况是，如果要删除的节点有两个子节点，这就比较复杂了。我们需要找到这个节点的右子树中的最小节点，把它替换到要删除的节点上。
     * 然后再删除掉这个最小节点，因为最小节点肯定没有左子节点（如果有左子结点，那就不是最小节点了），所以，我们可以应用上面两条规则来删除这个最小节点。
     * @param root
     * @param key
     * @return
     */
    static Node *del(Node *root, int key) {
        Node *target = root;            // target 指向要删除的节点，初始化指向根节点
        Node *targetFather = nullptr;   // targetFather 记录的是 target 的父节点
        while (target != nullptr && target->key != key) {
            targetFather = target;
            target = target->key < key ? target->right : target->left;
        }
        if (target == nullptr) {
            return nullptr;
        }

        // 第三种情况是，如果要删除的节点有两个子节点
        if (target->left != nullptr && target->right != nullptr) {  // 查找右子树中最小节点
            Node *min = target->right;
            Node *minFather = target;
            while (min->left != nullptr) {
                minFather = min;
                min = min->left;
            }
            // 删除掉这个最小节点，因为最小节点肯定没有左子节点（如果有左子结点，那就不是最小节点了）
            if (min->right != nullptr) {
                minFather->left = min->right;
            }
            // 我们需要找到这个节点的右子树中的最小节点，把它替换到要删除的节点上。
            target->key = min->key;
            target->value = min->value;
            delete min;
        }
        // 第二种情况是，如果要删除的节点只有一个子节点
        Node *child = nullptr;
        if (target->left != nullptr) {
            child = target->left;
        } else if (target->right != nullptr) {
            child = target->right;
        }

        if (targetFather == nullptr) {
            // 删除的是根节点
            root = child;
        } else if (targetFather->left == target) {
            targetFather->left = child;
        } else {
            targetFather->right = child;
        }
        return target;
    }

    void dump(const Node &node) {

    }

public:

    /**
     * 插入
     * @param key
     * @param val
     */
    void put(int key, const string &val) {
        put(root, key, val);
    }

    /**
     * 查询
     * @param key
     * @return
     */
    string const *find(int key) {
        Node *pNode = find(root, key);
        return pNode == nullptr ? nullptr : &pNode->value;
    }

    /**
     * 查找最大的
     * @return
     */
    string const *findBiggest() {
        Node *pNode = findBiggest(root);
        return pNode == nullptr ? nullptr : &pNode->value;
    }

    /**
     * 查找最小的
     * @return
     */
    string const *findSmallest() {
        Node *pNode = findSmallest(root);
        return pNode == nullptr ? nullptr : &pNode->value;
    }

    /**
     * 删除
     * @param key
     * @return
     */
    string const *del(int key) {
        Node *pNode = del(root, key);
        return pNode == nullptr ? nullptr : &pNode->value;
    }


    /**
     * 先序遍历:根结点--》左子树---》右子树
     */
    void preorder() {

    }

    /**
     * 中序遍历:左子树--》跟节点---》右子树
     */
    void inorder() {

    }

    /**
     * 后序遍历:左子树---》右子树-》根节点
     */
    void postorder() {

    }
};

#endif //DATA_STRUCTURE_BINARYSEARCHTREE_HPP
