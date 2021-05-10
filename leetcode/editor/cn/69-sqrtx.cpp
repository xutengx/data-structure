//实现 int sqrt(int x) 函数。 
//
// 计算并返回 x 的平方根，其中 x 是非负整数。 
//
// 由于返回类型是整数，结果只保留整数的部分，小数部分将被舍去。 
//
// 示例 1: 
//
// 输入: 4
//输出: 2
// 
//
// 示例 2: 
//
// 输入: 8
//输出: 2
//说明: 8 的平方根是 2.82842..., 
//     由于返回类型是整数，小数部分将被舍去。
// 
// Related Topics 数学 二分查找 
// 👍 675 👎 0


#include "functional"
#include "vector"
#include "assert.h"
#include "string"
#include "iostream"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int mySqrt(int x) {
        // x 最大值 2的32次方减一
        // 所以平方根最大就 2的15次方
        int idxMax = 1 << 16;

        function<unsigned int(unsigned int, unsigned int)> mySqrtReal;

        mySqrtReal = [&mySqrtReal, &x](unsigned int startIdx, unsigned int endIdx) -> unsigned int {
            if (startIdx + 1 == endIdx) {
                return startIdx;
            }
            unsigned int midIdx = (endIdx - startIdx) / 2 + startIdx;
            if (((unsigned int) midIdx * midIdx) < x) {
                return mySqrtReal(midIdx, endIdx);

            } else if (((unsigned int) midIdx * midIdx) > x) {
                return mySqrtReal(startIdx, midIdx);
            } else {
                return midIdx;
            }
        };
        return (int) mySqrtReal(0, idxMax);
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution solution;
    // assert(solution.reverse(123) == 321);

    int i = solution.mySqrt(2147395599);

    return 0;
}