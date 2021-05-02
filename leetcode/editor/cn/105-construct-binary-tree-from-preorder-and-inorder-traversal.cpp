//根据一棵树的前序遍历与中序遍历构造二叉树。 
//
// 注意: 
//你可以假设树中没有重复的元素。 
//
// 例如，给出 
//
// 前序遍历 preorder = [3,9,20,15,7]
//中序遍历 inorder = [9,3,15,20,7] 
//
// 返回如下的二叉树： 
//
//     3
//   / \
//  9  20
//    /  \
//   15   7 
// Related Topics 树 深度优先搜索 数组 
// 👍 1021 👎 0


#include "iostream"
#include "cassert"
#include "vector"
#include "string"
#include "functional"
#include "unordered_map"

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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        int treeSize = (int) inorder.size();
        // 多次查找，先建立索引
        unordered_map<int, int> preorderMap;
        unordered_map<int, int> inorderMap;
        for (int i = 0; i < treeSize; ++i) {
            preorderMap.emplace(preorder[i], i);
        }
        for (int i = 0; i < treeSize; ++i) {
            inorderMap.emplace(inorder[i], i);
        }

        // 倒序
        vector<int> rPreorder;
        auto rit = preorder.rbegin();
        for (; rit != preorder.rend(); ++rit) {
            rPreorder.push_back(*rit) ;
        }


        function<TreeNode *(int, int, int)> buildTreeReal;
        /**
         * @param rootIdxPreorder 前序遍历的头结点下标
         */
        buildTreeReal = [&buildTreeReal, &treeSize, &preorder, &inorder, &inorderMap, &preorderMap, &rPreorder](
                int rootIdxPreorder, int startIdxInorder, int endIdxInorder) -> TreeNode * {
            TreeNode *left, *right;
            int &rootValue = preorder[rootIdxPreorder];
            int &rootIdxInorder = inorderMap[rootValue];

            rPreorder.pop_back();

            if (rootIdxInorder == startIdxInorder) {
                left = nullptr;
            } else {
                int leftIdxPreorder = rootIdxPreorder + 1;
                left = buildTreeReal(leftIdxPreorder, startIdxInorder, rootIdxInorder - 1);
            }

            if (rootIdxInorder == endIdxInorder) {
                right = nullptr;
            } else {
                int rightValue = rPreorder.back();
                int rightIdxPreorder = preorderMap[rightValue];
                right = buildTreeReal(rightIdxPreorder, rootIdxInorder + 1, endIdxInorder);
            }
            return new TreeNode(rootValue, left, right);
        };

        return buildTreeReal(0, 0, (int) treeSize - 1);
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution solution;
    //
    vector<int> inta = {3, 9, 20, 15, 7};
    vector<int> intb = {9, 3, 15, 20, 7};
    TreeNode *pNode = solution.buildTree(inta, intb);
//    vector<int> inta2 = {1, 2};
//    vector<int> intb2 = {1, 2};
//    TreeNode *pNode2 = solution.buildTree(inta2, intb2);
//    vector<int> inta3 = {3,9,20,15,7};
//    vector<int> intb3 = {9,3,15,20,7};
//    TreeNode *pNode3 = solution.buildTree(inta3, intb3);

    return 0;
}