//假设你正在爬楼梯。需要 n 阶你才能到达楼顶。 
//
// 每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？ 
//
// 注意：给定 n 是一个正整数。 
//
// 示例 1： 
//
// 输入： 2
//输出： 2
//解释： 有两种方法可以爬到楼顶。
//1.  1 阶 + 1 阶
//2.  2 阶 
//
// 示例 2： 
//
// 输入： 3
//输出： 3
//解释： 有三种方法可以爬到楼顶。
//1.  1 阶 + 1 阶 + 1 阶
//2.  1 阶 + 2 阶
//3.  2 阶 + 1 阶
// 
// Related Topics 动态规划 
// 👍 1642 👎 0


#include "functional"
#include "vector"
#include "assert.h"
#include "string"
#include "iostream"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int climbStairs(int n) {
        // 多写几层，找规律:
        // 递归思路： f(n) = f(n-1) + f(n-2)  ->  f(n-1) = f(n-2) + f(n-3)
        // 迭代思路： f(n-1) = f(n-2) + f(n-3) ->  f(n) = f(n-1) + f(n-2)
        // 迭代思路： sum = b + a ->  f(n) = sum + b -> f(n) = (a + b) + b
        if (n == 1 || n == 2) {
            return n;
        }
        int a = 1;
        int b = 2;
        int sum = 0;
        for (int i = 3; i <= n; ++i) {
            sum = a + b;
            a = b;
            b = sum;
        }
        return sum;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution solution;
    // assert(solution.reverse(123) == 321);

    return 0;
}