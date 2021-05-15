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
#include "unordered_map"
#include "algorithm"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:

    /**
     * 升序
     * @param a
     * @param b
     * @return
     */
    static bool compare(int a, int b) {
        return a > b;
    }

    /**
     * 思路类似于青蛙跳楼梯，假如coins = [1,2,5],amout = 11 那么就是11可以从dp[10],dp[9],dp[6]3个地方到达， 所以状态dp[n] = min(dp[10],dp[9],dp[6]) + 1 就是表示n最少的方式
     * dp(n) = min{dp(n - coins[0]),dp(n - coins[1]), ...}
     * 时间复杂度 = amout * len(coins) ,以为二维表就这么大 空间复杂度 = amout
     */
    /**

     */
    int coinChange(vector<int> &coins, int amount) {
        int Max = amount + 1;
        // 1、状态数组DP table
        // 建长为amount+1的数组，且每个元素也初始化为amount+1（因为凑成amount金额的硬币数最多只可能等于amount（全用 1 元面值的硬币）），
        // 在遍历时如果金额凑不出则不更新，于是若最后结果仍然是amount + 1，则表示金额凑不出，返回-1
        vector<int> dp(amount + 1, Max);
        // 2、状态初始化
        dp[0] = 0;
        // 3、状态转移
        for (int i = 1; i <= amount; ++i) {
            for (int j = 0; j <= coins.size()-1; ++j) {
                if (i >=coins[j]) {   //为了避免出现dp[2-5]的情况
                    dp[i] = min(dp[i], dp[i - coins[j]] + 1);
                    //和剪绳子一样，加了上一轮j的dp[i]
                }
            }
        }
        //4、返回最终状态
        return dp[amount] > amount ? -1 : dp[amount];
    }

    /**
     * 解答成功:
     * 执行耗时:672 ms,击败了5.04% 的C++用户
     * 内存消耗:60.6 MB,击败了5.01% 的C++用户
     */
    int coinChange(vector<int> &coins, int amount) {
        // 提前响应
        if(amount == 0){
            return 0;
        }
        unordered_map<int, int> cache;
        // 倒序排列
        sort(coins.begin(), coins.end(), compare);
        unsigned int size = coins.size();
        // 边界终止
        if(size == 0){
            return -1;
        }

        function<int(int)> coinChangeReal;

        coinChangeReal = [&coinChangeReal, &size, &coins, &cache](int amounts) {
            if(cache.count(amounts)){
                return cache[amounts];
            }
            int min = -1;
            for (int i = 0; i < size; ++i) {
                if (amounts - coins[i] > 0) {
                    int minI = coinChangeReal(amounts - coins[i]);
                    if (minI == -1) {
                        continue;
                    } else if (min == -1 || min > minI) {
                        min = minI + 1;
                    }
                } else if (amounts - coins[i] == 0) {
                    min = 1;
                    break;
                }
            }
            cache[amounts] = min;
            return min;
        };
        return coinChangeReal(amount);
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution solution;
    //

    vector<int> t0 = {1,4,5};
    assert(solution.coinChange(t0, 8)== 2);

    vector<int> t1 = {1,2,5};
    int i = solution.coinChange(t1, 100);
    assert(solution.coinChange(t1, 100)== 20);

    vector<int> t2 = {186,419,83,408};
    assert(solution.coinChange(t2, 6249)== 20);

    vector<int> t3 = {3};
    assert(solution.coinChange(t3, 3)== 1);

    vector<int> t4 = {1,2,3,4,5};
    assert(solution.coinChange(t4, 5)== 1);
    vector<int> t5 = {1,2,3,4,5};
    assert(solution.coinChange(t5, 9)== 2);
    return 0;
}