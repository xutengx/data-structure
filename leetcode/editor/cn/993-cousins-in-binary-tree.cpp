//在二叉树中，根节点位于深度 0 处，每个深度为 k 的节点的子节点位于深度 k+1 处。 
//
// 如果二叉树的两个节点深度相同，但 父节点不同 ，则它们是一对堂兄弟节点。 
//
// 我们给出了具有唯一值的二叉树的根节点 root ，以及树中两个不同节点的值 x 和 y 。 
//
// 只有与值 x 和 y 对应的节点是堂兄弟节点时，才返回 true 。否则，返回 false。 
//
// 
//
// 示例 1： 
// 
//
// 
//输入：root = [1,2,3,4], x = 4, y = 3
//输出：false
// 
//
// 示例 2： 
// 
//
// 
//输入：root = [1,2,3,null,4,null,5], x = 5, y = 4
//输出：true
// 
//
// 示例 3： 
//
// 
//
// 
//输入：root = [1,2,3,null,4], x = 2, y = 3
//输出：false 
//
// 
//
// 提示： 
//
// 
// 二叉树的节点数介于 2 到 100 之间。 
// 每个节点的值都是唯一的、范围为 1 到 100 的整数。 
// 
//
// 
// Related Topics 树 广度优先搜索 
// 👍 180 👎 0


#include "iostream"
#include "cassert"
#include "vector"
#include "string"
#include "functional"

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
//leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    /**
     * 解答成功:
     * 执行耗时:0 ms,击败了100.00% 的C++用户
     * 内存消耗:10.5 MB,击败了97.58% 的C++用户
     * @param root
     * @param x
     * @param y
     * @return
     */
    bool isCousins(TreeNode *root, int x, int y) {
        TreeNode *xFather = nullptr;
        TreeNode *yFather = nullptr;
        int xFatherLevel = 0;
        int yFatherLevel = 0;

        function<void(TreeNode *,TreeNode *, int)> isCousinsReal;
        isCousinsReal = [&isCousinsReal, &x, &y, &xFather, &yFather, &xFatherLevel, &yFatherLevel](TreeNode *node, TreeNode *nodeFather, int level){
            if(node == nullptr){
                return ;
            }
            if (node->val == x) {
                xFatherLevel = level;
                xFather = nodeFather;
            } else if (node->val == y) {
                yFatherLevel = level;
                yFather = nodeFather;
            } else{
                isCousinsReal(node->left, node, level + 1);
                isCousinsReal(node->right, node, level + 1);
            }
        };
        isCousinsReal(root, nullptr, 0);
        if(nullptr != xFather && nullptr != yFather && xFather != yFather && xFatherLevel == yFatherLevel){
            return true;
        }
        return false;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution solution;
    // 
    return 0;
}