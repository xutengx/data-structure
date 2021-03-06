//给定一个数组 prices ，其中 prices[i] 是一支给定股票第 i 天的价格。 
//
// 设计一个算法来计算你所能获取的最大利润。你可以尽可能地完成更多的交易（多次买卖一支股票）。 
//
// 注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。 
//
// 
//
// 示例 1: 
//
// 
//输入: prices = [7,1,5,3,6,4]
//输出: 7
//解释: 在第 2 天（股票价格 = 1）的时候买入，在第 3 天（股票价格 = 5）的时候卖出, 这笔交易所能获得利润 = 5-1 = 4 。
//     随后，在第 4 天（股票价格 = 3）的时候买入，在第 5 天（股票价格 = 6）的时候卖出, 这笔交易所能获得利润 = 6-3 = 3 。
// 
//
// 示例 2: 
//
// 
//输入: prices = [1,2,3,4,5]
//输出: 4
//解释: 在第 1 天（股票价格 = 1）的时候买入，在第 5 天 （股票价格 = 5）的时候卖出, 这笔交易所能获得利润 = 5-1 = 4 。
//     注意你不能在第 1 天和第 2 天接连购买股票，之后再将它们卖出。因为这样属于同时参与了多笔交易，你必须在再次购买前出售掉之前的股票。
// 
//
// 示例 3: 
//
// 
//输入: prices = [7,6,4,3,1]
//输出: 0
//解释: 在这种情况下, 没有交易完成, 所以最大利润为 0。 
//
// 
//
// 提示： 
//
// 
// 1 <= prices.length <= 3 * 104 
// 0 <= prices[i] <= 104 
// 
// Related Topics 贪心算法 数组 
// 👍 1221 👎 0


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
     * 执行耗时:8 ms,击败了62.56% 的C++用户
     * 内存消耗:12.6 MB,击败了80.80% 的C++用户
     */
    int maxProfit(vector<int> &prices) {
        int pricesSize = (int) prices.size();
        int profit = 0;                     // 收益
        bool alreadyBought = false;         // 已经买入了
        int priceLeft;                   // 买入时的价格
        for (int i = 0; i < pricesSize; ++i) {
            // 最后一天, 循环结束
            if (i + 1 == pricesSize) {
                // 有就卖
                if (alreadyBought) {
                    profit += prices[i] - priceLeft;
                }
            }
                // 明天跌了，今天应该卖，卖不了就等着
            else if (prices[i] > prices[i + 1]) {
                if (alreadyBought) {
                    profit += prices[i] - priceLeft;
                    alreadyBought = false;
                }
            }
                // 明天涨了，今天应该买，买过呢就等着
            else {
                if (!alreadyBought) {
                    priceLeft = prices[i];
                    alreadyBought = true;
                }

            }
        }
        return profit;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution solution;
    // assert(solution.reverse(123) == 321);

    vector<int> t1 = {7, 1, 5, 3, 6, 4};
    assert(solution.maxProfit(t1) == 7);

    return 0;
}