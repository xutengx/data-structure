//给你一个字符串 s，找到 s 中最长的回文子串。 
//
// 
//
// 示例 1： 
//
// 
//输入：s = "babad"
//输出："bab"
//解释："aba" 同样是符合题意的答案。
// 
//
// 示例 2： 
//
// 
//输入：s = "cbbd"
//输出："bb"
// 
//
// 示例 3： 
//
// 
//输入：s = "a"
//输出："a"
// 
//
// 示例 4： 
//
// 
//输入：s = "ac"
//输出："a"
// 
//
// 
//
// 提示： 
//
// 
// 1 <= s.length <= 1000 
// s 仅由数字和英文字母（大写和/或小写）组成 
// 
// Related Topics 字符串 动态规划 
// 👍 3590 👎 0


#include "iostream"
#include "cassert"
#include "vector"
#include "string"
#include "functional"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    string longestPalindrome(string s) {

        const char *str = s.data();
        int strLength = s.size();
        // 当前结论
        string result;
        unsigned int resultLength = 0;

        //  a[x][y]=b[x*列数+y]
        // 因为后续代码会限定，j>i, 所以第二维不需要满长度
        // 0表示未处理，t表示是回文字符，f表示不是回文字符, n表示未处理
        char **cache = new char *[strLength];
        for (int i = 0; i < strLength; i++) {
            int tempLength = strLength - i + 1;
            char *pInt = new char[tempLength];
            for (int j = 0; j < tempLength; j++) {
                pInt[j] = 'n';
            }
            cache[i] = pInt;
        }

        function<bool(unsigned int, unsigned int)> longestPalindromeReal;

        longestPalindromeReal = [&longestPalindromeReal, &cache, &str, &strLength](unsigned int one,
                                                                                   unsigned int two) -> bool {
            if (cache[one][strLength - two] != 'n') {
                return cache[one][strLength - two] == 't';
            } else {
                bool flag;
                if (one > two) {
                    flag = false;
                } else if (one == two) {
                    flag = true;
                } else {
                    if (str[one] == str[two]) {
                        if (two - one == 1) {
                            flag = true;
                        } else {
                            flag = longestPalindromeReal(one + 1, two - 1);
                        }
                    } else {
                        flag = false;
                    }
                }
                cache[one][strLength - two] = flag ? 't' : 'f';
                return flag;
            }
        };
        // 执行
        for (int i = 0; i < strLength; i++) {
            // 快速结束 - 较短的没有必要弄（i 递增）
            if (resultLength >= (strLength - i)) {
                break;
            }
//            cout << "";
            for (int j = (strLength - 1); j >= i; j--) {
//                cout << "";
                // 快速结束 - 较短的没有必要弄（j 递减）
                if (resultLength >= (j - i + 1)) {
                    break;
                }
                if (longestPalindromeReal(i, j)) {
                    resultLength = j - i + 1;
                    result = s.substr(i, resultLength);
                }
            }
        }
        return result;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution solution;

    assert(solution.longestPalindrome("cbbd") == "bb");
    assert(solution.longestPalindrome("bb") == "bb");
    assert(solution.longestPalindrome("babad") == "bab");
    assert(solution.longestPalindrome("b") == "b");
    assert(solution.longestPalindrome("baaad") == "aaa");
    assert(solution.longestPalindrome("acbcbbca") == "cbbc");

    return 0;
}