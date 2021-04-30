//给你一个 32 位的有符号整数 x ，返回将 x 中的数字部分反转后的结果。 
//
// 如果反转后整数超过 32 位的有符号整数的范围 [−231, 231 − 1] ，就返回 0。 
//假设环境不允许存储 64 位整数（有符号或无符号）。
//
// 
//
// 示例 1： 
//
// 
//输入：x = 123
//输出：321
// 
//
// 示例 2： 
//
// 
//输入：x = -123
//输出：-321
// 
//
// 示例 3： 
//
// 
//输入：x = 120
//输出：21
// 
//
// 示例 4： 
//
// 
//输入：x = 0
//输出：0
// 
//
// 
//
// 提示： 
//
// 
// -231 <= x <= 231 - 1 
// 
// Related Topics 数学 
// 👍 2737 👎 0


#include "functional"
#include "vector"
#include "assert.h"
#include "string"
#include "iostream"
#include "math.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int reverse(int x) {
        bool isPositiveNumber = x >= 0;     // 是正数吗

        int temp = x;
        int length = 0;         // x 的位数
        while (temp) {
            if (length++ > 10) {
                return 0;
            }
            temp /= 10;
        }

        unsigned long long absoluteValue = isPositiveNumber ? x : (long long) -1 * x;

        for (int i = 0; i < length / 2; i++) {
            unsigned long long valOne = (absoluteValue / (long long) pow(10, i)) % 10;
            unsigned long long valTwo = (absoluteValue / (long long) pow(10, length - i - 1)) % 10;
            absoluteValue -= valOne * (long long) pow(10, i);
            absoluteValue -= valTwo * (long long) pow(10, length - i - 1);
            valOne = valOne + valTwo;
            valTwo = valOne - valTwo;
            valOne = valOne - valTwo;
            absoluteValue += valOne * (long long) pow(10, i);
            unsigned long long d = valTwo * (long long) pow(10, length - i - 1);
            absoluteValue += d;
        }
        // 防止溢出
        unsigned int one = 1;
        if (isPositiveNumber && absoluteValue > (one << 31) - 1) {
            return 0;
        } else if (!isPositiveNumber && absoluteValue > (one << 31)) {
            return 0;
        } else {
            return isPositiveNumber ? absoluteValue : -1 * absoluteValue;
        }
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution solution;
    //
    assert(solution.reverse(0) == 0);
    assert(solution.reverse(2) == 2);
    assert(solution.reverse(25) == 52);
    assert(solution.reverse(123) == 321);
    assert(solution.reverse(12003) == 30021);
    assert(solution.reverse(-1123) == -3211);
    assert(solution.reverse(-2147483648) == 0);
    assert(solution.reverse(1534236469) == 0);
    return 0;
}