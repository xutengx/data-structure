//给定一个二叉树，判断其是否是一个有效的二叉搜索树。 
//
// 假设一个二叉搜索树具有如下特征： 
//
// 
// 节点的左子树只包含小于当前节点的数。 
// 节点的右子树只包含大于当前节点的数。 
// 所有左子树和右子树自身必须也是二叉搜索树。 
// 
//
// 示例 1: 
//
// 输入:
//    2
//   / \
//  1   3
//输出: true
// 
//
// 示例 2: 
//
// 输入:
//    5
//   / \
//  1   4
//     / \
//    3   6
//输出: false
//解释: 输入为: [5,1,4,null,null,3,6]。
//     根节点的值为 5 ，但是其右子节点值为 4 。
// 
// Related Topics 树 深度优先搜索 递归 
// 👍 1053 👎 0


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

    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

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
    bool isValidBST(TreeNode *root) {

        long fatherVal = LONG_MIN;

        function<bool(TreeNode *)> isValidBSTReal;

        /**
         * 中序遍历结果为升序，如果不满足升序，则不是二叉搜索树
         * @param fatherNode 当前节点
         * @return
         */
        isValidBSTReal = [&isValidBSTReal, &fatherVal](TreeNode *node) {
            if (node == nullptr) {
                return true;
            }
            if (!isValidBSTReal(node->left)) {
                return false;
            }
            if (fatherVal >= node->val) {
                return false;
            }
            fatherVal = node->val;
            return isValidBSTReal(node->right);
        };

        return isValidBSTReal(root);
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution solution;
    //
    TreeNode *pNode5 = new TreeNode(5);
    TreeNode *pNode1 = new TreeNode(1);
    TreeNode *pNode4 = new TreeNode(4);
    TreeNode *pNode3 = new TreeNode(3);
    TreeNode *pNode6 = new TreeNode(6);

    pNode5->left = pNode1;
    pNode5->right = pNode4;
    pNode4->left = pNode3;
    pNode4->right = pNode6;

    assert(!solution.isValidBST(pNode5));
    return 0;
}