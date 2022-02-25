//编写一个函数来查找字符串数组中的最长公共前缀。 
//
// 如果不存在公共前缀，返回空字符串 ""。 
//
// 
//
// 示例 1： 
//
// 
//输入：strs = ["flower","flow","flight"]
//输出："fl"
// 
//
// 示例 2： 
//
// 
//输入：strs = ["dog","racecar","car"]
//输出：""
//解释：输入不存在公共前缀。 
//
// 
//
// 提示： 
//
// 
// 1 <= strs.length <= 200 
// 0 <= strs[i].length <= 200 
// strs[i] 仅由小写英文字母组成 
// 
// Related Topics 字符串 👍 2050 👎 0


#include "functional"
#include "vector"
#include "assert.h"
#include "string"
#include "iostream"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        string commonPrefix;
        if (strs.empty()) {
            return commonPrefix;
        }
        string guessCommonPrefix = strs.at(0);

        for (int i = 0; i < guessCommonPrefix.size(); i++) {
            char &basicChar = guessCommonPrefix.at(i);
            for (const auto &str: strs) {
                if (i >= str.size() || basicChar != str.at(i)) {
                    goto endFlag;
                }
            }
            commonPrefix.append(1, basicChar);
        }
        endFlag :
        return commonPrefix;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution solution;
    //
    vector<string> testStr = {"flower","flow","flight"};
    const string &basicString = solution.longestCommonPrefix(testStr);
    cout << basicString;
    assert(basicString == "fl");

    return 0;
}