//给定一个数组 prices ，它的第 i 个元素 prices[i] 表示一支给定股票第 i 天的价格。 
//
// 你只能选择 某一天 买入这只股票，并选择在 未来的某一个不同的日子 卖出该股票。设计一个算法来计算你所能获取的最大利润。 
//
// 返回你可以从这笔交易中获取的最大利润。如果你不能获取任何利润，返回 0 。 
//
// 
//
// 示例 1： 
//
// 
//输入：[7,1,5,3,6,4]
//输出：5
//解释：在第 2 天（股票价格 = 1）的时候买入，在第 5 天（股票价格 = 6）的时候卖出，最大利润 = 6-1 = 5 。
//     注意利润不能是 7-1 = 6, 因为卖出价格需要大于买入价格；同时，你不能在买入前卖出股票。
// 
//
// 示例 2： 
//
// 
//输入：prices = [7,6,4,3,1]
//输出：0
//解释：在这种情况下, 没有交易完成, 所以最大利润为 0。
// 
//
// 
//
// 提示： 
//
// 
// 1 <= prices.length <= 105 
// 0 <= prices[i] <= 104 
// 
// Related Topics 数组 动态规划 
// 👍 1621 👎 0


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
     * 执行耗时:172 ms,击败了17.81% 的C++用户
     * 内存消耗:93.4 MB,击败了17.12% 的C++用户
     */
    int maxProfit(vector<int> &prices) {
        int ans = 0;
        vector<int> St;
        prices.emplace_back(-1);
        for (int i = 0; i < prices.size(); ++ i){
            while (!St.empty() && St.back() > prices[i]){
                ans = std::max(ans, St.back() - St.front());
                St.pop_back();
            }
            St.emplace_back(prices[i]);
        }
        return ans;
    }

    /**
     * 解答成功:
     * 执行耗时:156 ms,击败了31.45% 的C++用户
     * 内存消耗:91.2 MB,击败了31.09% 的C++用户
     */
//    int maxProfit(vector<int> &prices) {
//        int pricesSize = (int)prices.size();
//        int minPrice = prices[0], maxPrice = 0;
//
//        for (int i = 0; i < pricesSize; ++i) {
//            // 历史以来 买入的最小值
//            minPrice = min(prices[i], minPrice);
//            // 若今天卖出，是不是最大值呢， 是有记一下，不是就算叻
//            maxPrice = max(prices[i] - minPrice, maxPrice);
//        }
//        return maxPrice;
//    }

    /**
     * 解答成功:
     * 执行耗时:1888 ms,击败了5.13% 的C++用户
     * 内存消耗:90.8 MB,击败了100.00% 的C++用户
     */
//    int maxProfit(vector<int> &prices) {
//        int pricesSize = (int)prices.size();
//        int res = 0;
//        int minLeft, maxRight, maxRightIdx;
//
//        for (int i = 0; i < pricesSize; ++i) {
//            // 越界检查 && 新的左节点大于原左节点
//            if (i > 0 && prices[i] >= minLeft) {
//                continue;
//            }
//            minLeft = prices[i];
//            // 最大右值仍然有效;
//            if(i < maxRightIdx){
//                res = max(res, maxRight - minLeft);
//                continue;
//            }
//
//            for (int j = pricesSize - 1; j > i; --j) {
//                // 越界检查 && 新的右节点小于原由节点
//                if (j < pricesSize - 1 && prices[j] <= maxRight) {
//                    continue;
//                }
//                maxRight = prices[j];
//                maxRightIdx = j;
//                res = max(res, prices[j] - prices[i]);
//            }
//        }
//        return res;
//    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution solution;
    // assert(solution.reverse(123) == 321);

    vector<int> t1 = {7, 1, 5, 3, 6, 4};
    solution.maxProfit(t1);
    vector<int> t2 = {};
    solution.maxProfit(t2);
    return 0;
}