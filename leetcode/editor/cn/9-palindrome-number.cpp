//给你一个整数 x ，如果 x 是一个回文整数，返回 true ；否则，返回 false 。 
//
// 回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。例如，121 是回文，而 123 不是。 
//
// 
//
// 示例 1： 
//
// 
//输入：x = 121
//输出：true
// 
//
// 示例 2： 
//
// 
//输入：x = -121
//输出：false
//解释：从左向右读, 为 -121 。 从右向左读, 为 121- 。因此它不是一个回文数。
// 
//
// 示例 3： 
//
// 
//输入：x = 10
//输出：false
//解释：从右向左读, 为 01 。因此它不是一个回文数。
// 
//
// 示例 4： 
//
// 
//输入：x = -101
//输出：false
// 
//
// 
//
// 提示： 
//
// 
// -231 <= x <= 231 - 1 
// 
//
// 
//
// 进阶：你能不将整数转为字符串来解决这个问题吗？ 
// Related Topics 数学 
// 👍 1489 👎 0


#include "iostream"
#include "cassert"
#include "vector"
#include "string"
#include "functional"
#include "math.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }
        // 数字的位数
        int length = 0;
        int xTemp = x;
        while (xTemp) {
            length++;
            xTemp /= 10;
        }

        for (int i = 0; i < length / 2; i++) {
            // 当前位的值 123 3
            int one = (x / (int)pow(10, i)) % 10;
            // 对应位置
            int two = (x / (int)pow(10, length - i - 1)) % 10;

            if(one != two){
                return false;
            }
        }
        return true;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution solution;
    //
    assert(solution.isPalindrome(123) == false);
    assert(solution.isPalindrome(-123) == false);
    assert(solution.isPalindrome(232) == true);
    assert(solution.isPalindrome(1) == true);
    assert(solution.isPalindrome(0) == true);
    assert(solution.isPalindrome(-1) == false);
    assert(solution.isPalindrome(22) == true);
    assert(solution.isPalindrome(-22) == false);

    return 0;
}