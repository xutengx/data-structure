//给你一棵所有节点为非负值的二叉搜索树，请你计算树中任意两节点的差的绝对值的最小值。 
//
// 
//
// 示例： 
//
// 输入：
//
//   1
//    \
//     3
//    /
//   2
//
//输出：
//1
//
//解释：
//最小绝对差为 1，其中 2 和 1 的差的绝对值为 1（或者 2 和 3）。
// 
//
// 
//
// 提示： 
//
// 
// 树中至少有 2 个节点。 
// 本题与 783 https://leetcode-cn.com/problems/minimum-distance-between-bst-nodes/ 
//相同 
// 
// Related Topics 树 深度优先搜索 广度优先搜索 二叉搜索树 二叉树 
// 👍 281 👎 0


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
     * 1. 中序遍历（左子树->根节点->右子树）时，节点的遍历顺序是严格从小到大。
     * 2. 任意两节点差值的最小值（绝对值），在顺序结构中，一定是由相邻的节点差值产生。
     * 综上所述：中序遍历时，依次判断当前的差值和历史的差值即可。
     * @param root
     * @return
     */
    int getMinimumDifference(TreeNode *root) {
        // 当前最小差值
        int minDifference = INT32_MAX - 1;
        // 前一个元素的值（因为所有节点为非负值的二叉搜索树， 所以这儿使用任意负数即可）
        int preEle = -1;
        // 声明
        function<void(const TreeNode *)> inOrderTraverse;
        inOrderTraverse = [&inOrderTraverse, &minDifference, &preEle](const TreeNode *node) {
            if (node == nullptr) {
                return;
            }
            // 递归完成中序遍历（左子树）
            inOrderTraverse(node->left);
            // 判断并记录差值
            int difference = node->val - preEle;
            if (difference < minDifference) {
                // 跳过第一个元素
                if(preEle >= 0){
                    minDifference = difference;
                }
            }
            // 记录前一个元素的值
            preEle = node->val;
            // 递归完成中序遍历（右子树）
            inOrderTraverse(node->right);
        };

        // 执行
        inOrderTraverse(root);
        return minDifference;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution solution;
    //
    TreeNode *pNode1 = new TreeNode(1);
    TreeNode *pNode2 = new TreeNode(3184);
    TreeNode *pNode3 = new TreeNode(1434, pNode1, nullptr);
    TreeNode *pNode4 = new TreeNode(3048, nullptr, pNode2);
    TreeNode *pNode5 = new TreeNode(1564, pNode3, pNode4);

    int res = solution.getMinimumDifference(pNode5);
    cout << endl << res;
    assert(res == 130);
    return 0;
}