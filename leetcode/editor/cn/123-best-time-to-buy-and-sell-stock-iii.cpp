//给定一个数组，它的第 i 个元素是一支给定的股票在第 i 天的价格。 
//
// 设计一个算法来计算你所能获取的最大利润。你最多可以完成 两笔 交易。 
//
// 注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。 
//
// 
//
// 示例 1: 
//
// 
//输入：prices = [3,3,5,0,0,3,1,4]
//输出：6
//解释：在第 4 天（股票价格 = 0）的时候买入，在第 6 天（股票价格 = 3）的时候卖出，这笔交易所能获得利润 = 3-0 = 3 。
//     随后，在第 7 天（股票价格 = 1）的时候买入，在第 8 天 （股票价格 = 4）的时候卖出，这笔交易所能获得利润 = 4-1 = 3 。 
//
// 示例 2： 
//
// 
//输入：prices = [1,2,3,4,5]
//输出：4
//解释：在第 1 天（股票价格 = 1）的时候买入，在第 5 天 （股票价格 = 5）的时候卖出, 这笔交易所能获得利润 = 5-1 = 4 。   
//     注意你不能在第 1 天和第 2 天接连购买股票，之后再将它们卖出。   
//     因为这样属于同时参与了多笔交易，你必须在再次购买前出售掉之前的股票。
// 
//
// 示例 3： 
//
// 
//输入：prices = [7,6,4,3,1] 
//输出：0 
//解释：在这个情况下, 没有交易完成, 所以最大利润为 0。 
//
// 示例 4： 
//
// 
//输入：prices = [1]
//输出：0
// 
//
// 
//
// 提示： 
//
// 
// 1 <= prices.length <= 105 
// 0 <= prices[i] <= 105 
// 
// Related Topics 数组 动态规划 
// 👍 767 👎 0


#include "functional"
#include "vector"
#include "assert.h"
#include "string"
#include "iostream"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:

    /**
     * 解答成功:
     * 执行耗时:140 ms,击败了84.99% 的C++用户
     * 内存消耗:73.3 MB,击败了88.42% 的C++用户
     */
    int maxProfit(vector<int> &prices) {
        int priceSize = (int) prices.size();
        int buy1, buy2, sell1, sell2;
        buy1 = buy2 = prices[0];
        sell1 = sell2 = 0;
        for (int i = 0; i < priceSize; ++i) {
            // 有史以来最便宜的买入价
            buy1 = min(buy1, prices[i]);
            // 如果 今天的第一次卖出会是收益最多的吗？
            sell1 = max(sell1, prices[i] - buy1);

            // 如果 今天进行第2次买入，那么收益会降低
            buy2 = min(buy2 , prices[i] - sell1);
            // 如果 今天的第2次卖出，会是最大总收益吗？
            sell2 = max(sell2, prices[i] - buy2);
        }
        return sell2;
    }

    /**
     * 运行失败:
     * Time Limit Exceeded
     */
//    int maxProfit(vector<int> &prices) {
//        int maxProfit = 0;
//        int priceSize = (int) prices.size();
//
//        /**
//         * 一段时间内的一次买入卖出的最大收益
//         */
//        function<int(int, int)> oneMaxProfit;
//        oneMaxProfit = [&prices](int startIdx, int endIdx) {
//            int profit = 0;                         // 最大收益
//            int priceLow = prices[startIdx];        // 买入价格
//            for (int i = startIdx; i <= endIdx; ++i) {
//                // 历史以来的最低买入价格
//                priceLow = min(priceLow, prices[i]);
//                // 如果今天卖出，会是最大收益吗？
//                profit = max(profit, prices[i] - priceLow);
//            }
//            return profit;
//        };
//
//        /**
//         * 分割后，分别求出2侧的最大收益
//         * 再比较所有分割中最大的收益
//         */
//        for (int i = 0; i < priceSize; ++i) {
//            int leftMax = oneMaxProfit(0, i);
//            int rightMax = oneMaxProfit(i, priceSize - 1);
//            maxProfit = max(maxProfit, leftMax + rightMax);
//        }
//        return maxProfit;
//    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution solution;
    // assert(solution.reverse(123) == 321);
    vector<int> t1 = {3, 3, 5, 0, 0, 3, 1, 4};
    assert(solution.maxProfit(t1) == 6);

    return 0;
}