//给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。 
//
// 
//
// 示例 1: 
//
// 
//输入: s = "abcabcbb"
//输出: 3 
//解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
// 
//
// 示例 2: 
//
// 
//输入: s = "bbbbb"
//输出: 1
//解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
// 
//
// 示例 3: 
//
// 
//输入: s = "pwwkew"
//输出: 3
//解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
//     请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
// 
//
// 示例 4: 
//
// 
//输入: s = ""
//输出: 0
// 
//
// 
//
// 提示： 
//
// 
// 0 <= s.length <= 5 * 104 
// s 由英文字母、数字、符号和空格组成 
// 
// Related Topics 哈希表 双指针 字符串 Sliding Window 
// 👍 5387 👎 0


#include "functional"
#include "string"
#include "vector"
#include "assert.h"
#include "iostream"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // 最终响应
        int res = 0;
        // 每个子串的长度
        int resTemp = 0;

        // 目标子串起始位置
        int startIdx = 0;
        // 目标子串结束位置
        int endIdx = 0;
        unsigned long long int size = s.size();
        const char *arr = s.data();

        while (endIdx < size) {
            // 记录相对位置第几位出现的重复
            int we = 0;
            // 检查重复
            for (int i = startIdx; i < endIdx; i++) {
                // 出现重复
                if (arr[i] == arr[endIdx]) {
                    // 尽可能的向前进
                    startIdx += (we + 1);
                    // 初始化新的子列长度
                    resTemp -= (we + 1);
                    break;
                } else {
                    we++;
                }
            }
            endIdx++;
            resTemp++;

            if (res < resTemp) {
                res = resTemp;
            }
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution solution;
    //
    int b = solution.lengthOfLongestSubstring("bbbbb");
    cout << " -- " << b << "\n";
    assert(b == 1);

    int i = solution.lengthOfLongestSubstring("pwwkew");
    cout << " -- " << i << "\n";
    assert(i == 3);

    int j = solution.lengthOfLongestSubstring("abcfcqwertt");
    cout << " -- " << j << "\n";
    assert(j == 7);

    return 0;
}