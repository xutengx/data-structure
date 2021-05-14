//给定不同面额的硬币 coins 和一个总金额 amount。编写一个函数来计算可以凑成总金额所需的最少的硬币个数。如果没有任何一种硬币组合能组成总金额，返回
// -1。 
//
// 你可以认为每种硬币的数量是无限的。 
//
// 
//
// 示例 1： 
//
// 
//输入：coins = [1, 2, 5], amount = 11
//输出：3 
//解释：11 = 5 + 5 + 1 
//
// 示例 2： 
//
// 
//输入：coins = [2], amount = 3
//输出：-1 
//
// 示例 3： 
//
// 
//输入：coins = [1], amount = 0
//输出：0
// 
//
// 示例 4： 
//
// 
//输入：coins = [1], amount = 1
//输出：1
// 
//
// 示例 5： 
//
// 
//输入：coins = [1], amount = 2
//输出：2
// 
//
// 
//
// 提示： 
//
// 
// 1 <= coins.length <= 12 
// 1 <= coins[i] <= 231 - 1 
// 0 <= amount <= 104 
// 
// Related Topics 动态规划 
// 👍 1265 👎 0


#include "iostream"
#include "cassert"
#include "vector"
#include "string"
#include "functional"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    /**
     * 思路类似于青蛙跳楼梯，假如coins = [1,2,5],amout = 11 那么就是11可以从dp[10],dp[9],dp[6]3个地方到达， 所以状态dp[n] = min(dp[10],dp[9],dp[6]) + 1 就是表示n最少的方式
     * dp(n) = min{dp(n - coins[0]),dp(n - coins[1]), ...}
     * 时间复杂度 = amout * len(coins) ,以为二维表就这么大 空间复杂度 = amout
     */
    int coinChange(vector<int> &coins, int amount) {
        unsigned int size = coins.size();

        int *cache = new int[size + 1];
        for (int i = 0; i < size; ++i) {
            cache[amount[i]] = 0;
        }
        function<int(int)> coinChangeReal;

        coinChangeReal = [&coinChangeReal, &size, &coins](int amounts) {
            if (amounts){

            }
            int min = INT_MAX;
            for (int i = 0; i < size; ++i) {
                int minI = coinChangeReal(amounts - coins[i]);
                if (min > minI) {
                    min = minI;
                }
            }
            return min;
        };

    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution solution;
    // 
    return 0;
}