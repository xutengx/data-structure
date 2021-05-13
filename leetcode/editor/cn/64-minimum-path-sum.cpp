//给定一个包含非负整数的 m x n 网格 grid ，请找出一条从左上角到右下角的路径，使得路径上的数字总和为最小。 
//
// 说明：每次只能向下或者向右移动一步。 
//
// 
//
// 示例 1： 
//
// 
//输入：grid = [[1,3,1],[1,5,1],[4,2,1]]
//输出：7
//解释：因为路径 1→3→1→1→1 的总和最小。
// 
//
// 示例 2： 
//
// 
//输入：grid = [[1,2,3],[4,5,6]]
//输出：12
// 
//
// 
//
// 提示： 
//
// 
// m == grid.length 
// n == grid[i].length 
// 1 <= m, n <= 200 
// 0 <= grid[i][j] <= 100 
// 
// Related Topics 数组 动态规划 
// 👍 874 👎 0


#include "iostream"
#include "cassert"
#include "vector"
#include "string"
#include "functional"
#include "queue"
#include "unordered_map"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int minPathSum(vector<vector<int>> &grid) {
//        unordered_map<string, int> visited;
        int res = INT_MAX;
        unsigned int oneSize = grid.size();
        unsigned int twoSize = grid.at(0).size();
        vector<vector<int> > visited(oneSize, vector<int>(twoSize, -1));

        function<void(int, int, int)> minPathSumReal;

        minPathSumReal = [&grid, &res, &visited, &minPathSumReal, &oneSize, &twoSize](int sum, int one, int two) {
            // 越界，则中断
            if (one == oneSize || two == twoSize) {
                return;
            }
            // 缓存查找
            // 缓存中已有更优答案，则中断
            if (visited[one][two] != -1 && visited[one][two] <= sum) {
                return;
            } else {
                visited[one][two] = sum;
            }
            int val = sum + grid[one][two];
            // 到达终点
            if (one == oneSize - 1 && two == twoSize - 1) {
                if (res > val) {
                    res = val;
                }
                return;
            }
            // 左边节点
            minPathSumReal(val, one + 1, two);
            // 下边节点
            minPathSumReal(val, one, two + 1);
        };
        minPathSumReal(0, 0, 0);
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution solution;
    // 
    return 0;
}