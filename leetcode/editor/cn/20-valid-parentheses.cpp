//给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。 
//
// 有效字符串需满足： 
//
// 
// 左括号必须用相同类型的右括号闭合。 
// 左括号必须以正确的顺序闭合。 
// 
//
// 
//
// 示例 1： 
//
// 
//输入：s = "()"
//输出：true
// 
//
// 示例 2： 
//
// 
//输入：s = "()[]{}"
//输出：true
// 
//
// 示例 3： 
//
// 
//输入：s = "(]"
//输出：false
// 
//
// 示例 4： 
//
// 
//输入：s = "([)]"
//输出：false
// 
//
// 示例 5： 
//
// 
//输入：s = "{[]}"
//输出：true 
//
// 
//
// 提示： 
//
// 
// 1 <= s.length <= 104 
// s 仅由括号 '()[]{}' 组成 
// 
// Related Topics 栈 字符串 
// 👍 2384 👎 0


#include "iostream"
#include "cassert"
#include "vector"
#include "string"
#include "functional"
#include "stack"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool isValid(string s) {
        const char *data = s.data();
        unsigned long length = s.size();

        stack<char> ss;
        for (int i = 0; i < length; ++i) {
            if (data[i] == '(' || data[i] == '[' || data[i] == '{') {
                ss.push(data[i]);
            } else {
                if (ss.empty()) {
                    return false;
                }
                char ke;
                switch (data[i]) {
                    case ')':
                        ke = '(';
                        break;
                    case ']':
                        ke = '[';
                        break;
                    case '}':
                        ke = '{';
                        break;
                    default:
                        return false;
                }
                if (ss.top() == ke) {
                    ss.pop();
                } else {
                    return false;
                }
            }
        }
        return ss.empty();
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution solution;
    //
    assert(solution.isValid("()[]{}"));
    assert(!solution.isValid("([]{}"));
    assert(!solution.isValid("([]{}))"));
    return 0;
}