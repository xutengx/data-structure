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
    /**
     * 状态定义：设 dp 为大小 mtimesn  矩阵，其中 dp[i][j] 的值代表直到走到 (i,j) 的最小路径和。
     * 转移方程：题目要求，只能向右或向下走，换句话说，当前单元格 (i,j) 只能从左方单元格 (i-1,j) 或上方单元格 (i,j-1) 走到，因此只需要考虑矩阵左边界和上边界。
     * 走到当前单元格 (i,j) 的最小路径和 = “从左方单元格 (i-1,j) 与 从上方单元格 (i,j-1) 走来的 两个最小路径和中较小的 ” + 当前单元格值 grid[i][j] 。具体分为以下 4 种情况：
     * 1. 当左边和上边都不是矩阵边界时： 即当i != 0  , j != 0  时，dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j] ；
     * 2. 当只有左边是矩阵边界时： 只能从上面来，即当i == 0, j != 0  时， dp[i][j] = dp[i][j - 1] + grid[i][j] ；
     * 3. 当只有上边是矩阵边界时： 只能从左面来，即当i != 0, j == 0  时， dp[i][j] = dp[i - 1][j] + grid[i][j] ；
     * 4. 当左边和上边都是矩阵边界时： 即当i == 0, j == 0时，其实就是起点， dp[i][j] = grid[i][j]；
     * 初始状态：dp 初始化即可，不需要修改初始 0 值。
     * 返回值：返回 dp 矩阵右下角值，即走到终点的最小路径和。
     * 注意：其实我们完全不需要建立 dp 矩阵浪费额外空间，直接遍历 grid[i][j] 修改即可。这是因为：grid[i][j] = min(grid[i - 1][j], grid[i][j - 1]) + grid[i][j] ；
     * 原 grid 矩阵元素中被覆盖为 dp 元素后（都处于当前遍历点的左上方），不会再被使用到。
     *
     * 解答成功:
     * 执行耗时:12 ms,击败了57.56% 的C++用户
     * 内存消耗:9.4 MB,击败了85.28% 的C++用户
     */
    int minPathSum(vector<vector<int>> &grid) {
        unsigned int oneSize = grid.size();
        unsigned int twoSize = grid.at(0).size();

        for (int i = 0; i < oneSize; ++i) {
            for (int j = 0; j < twoSize; ++j) {
                // 到当前位置时，的最小值
                // 当前位置是起点时，最小点就是自己
                if(i == 0 && j == 0){
                    continue;
                }
                // 当前位置是，一维的边界
                else if(i == 0){
                    grid[i][j] += grid[i][j-1];
                }
                // 当前位置是，二维的边界
                else if(j == 0){
                    grid[i][j] += grid[i-1][j];
                }
                // 当前位置是 中间部分时，最小的值，就是由上边或者左边的最小值而来
                else{
                    grid[i][j] += grid[i-1][j] < grid[i][j-1] ? grid[i-1][j] : grid[i][j-1];
                }
            }
        }
        return grid[oneSize-1][twoSize-1];
    }

    /**
     * 解答成功:
     * 执行耗时:1476 ms,击败了5.62% 的C++用户
     * 内存消耗:10 MB,击败了5.27% 的C++用户
     */
//    int minPathSum(vector<vector<int>> &grid) {
//        int res = INT_MAX;
//        unsigned int oneSize = grid.size();
//        unsigned int twoSize = grid.at(0).size();
//        vector<vector<int> > visited(oneSize, vector<int>(twoSize, -1));
//
//        function<void(int, int, int)> minPathSumReal;
//
//        minPathSumReal = [&grid, &res, &visited, &minPathSumReal, &oneSize, &twoSize](int sum, int one, int two) {
//            // 越界，则中断
//            if (one == oneSize || two == twoSize) {
//                return;
//            }
//            // 缓存查找
//            // 缓存中已有更优答案，则中断
//            if (visited[one][two] != -1 && visited[one][two] <= sum) {
//                return;
//            } else {
//                visited[one][two] = sum;
//            }
//            int val = sum + grid[one][two];
//            // 到达终点
//            if (one == oneSize - 1 && two == twoSize - 1) {
//                if (res > val) {
//                    res = val;
//                }
//                return;
//            }
//            // 左边节点
//            minPathSumReal(val, one + 1, two);
//            // 下边节点
//            minPathSumReal(val, one, two + 1);
//        };
//        minPathSumReal(0, 0, 0);
//        return res;
//    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution solution;
    // 
    return 0;
}