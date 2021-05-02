//给你一个只包含 '(' 和 ')' 的字符串，找出最长有效（格式正确且连续）括号子串的长度。 
//
// 
//
// 
// 
// 示例 1： 
//
// 
//输入：s = "(()"
//输出：2
//解释：最长有效括号子串是 "()"
// 
//
// 示例 2： 
//
// 
//输入：s = ")()())"
//输出：4
//解释：最长有效括号子串是 "()()"
// 
//
// 示例 3： 
//
// 
//输入：s = ""
//输出：0
// 
//
// 
//
// 提示： 
//
// 
// 0 <= s.length <= 3 * 104 
// s[i] 为 '(' 或 ')' 
// 
// 
// 
// Related Topics 字符串 动态规划 
// 👍 1288 👎 0


#include "iostream"
#include "cassert"
#include "vector"
#include "string"
#include "functional"
#include "unordered_map"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int longestValidParentheses(string s) {
        const char *data = s.data();
        int dataSize = (int) s.size();

        int left = 0;
        int right = 0;
        int maxlength = 0;
        int maxlengthTemp = 0;

        for (int i = 0; i < dataSize; ++i) {
            if (data[i] == '(') {
                left++;
            } else {
                right++;
            }
            if (left == right) {
                maxlengthTemp += (2 * right);
                if (maxlength < maxlengthTemp) {
                    maxlength = maxlengthTemp;
                };
                left = 0;
                right = 0;
            } else if (left < right) {
                if (maxlength < maxlengthTemp) {
                    maxlength = maxlengthTemp;
                }
                maxlengthTemp = 0;
                left = 0;
                right = 0;
            }
        }
        right = left = maxlengthTemp = 0;
        for (int i = dataSize - 1; i >= 0; --i) {
            if (data[i] == ')') {
                right++;
            } else {
                left++;
            }
            if (left == right) {
                maxlengthTemp += (2 * left);
                if (maxlength < maxlengthTemp) {
                    maxlength = maxlengthTemp;
                }
                left = 0;
                right = 0;
            } else if (left > right) {
                if (maxlength < maxlengthTemp) {
                    maxlength = maxlengthTemp;
                };
                maxlengthTemp = 0;
                left = 0;
                right = 0;
            }
        }
        return maxlength;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution solution;
    //

    assert(solution.longestValidParentheses("(()") == 2);
    assert(solution.longestValidParentheses("()(()") == 2);
    assert(solution.longestValidParentheses("()(())") == 6);
    int i = solution.longestValidParentheses("()(())(((((()()()()()");
    assert(solution.longestValidParentheses("()(())(((((()()()()()") == 10);

    return 0;
}