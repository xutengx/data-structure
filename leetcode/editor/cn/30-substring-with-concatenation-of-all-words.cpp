//给定一个字符串 s 和一些长度相同的单词 words。找出 s 中恰好可以由 words 中所有单词串联形成的子串的起始位置。 
//
// 注意子串要与 words 中的单词完全匹配，中间不能有其他字符，但不需要考虑 words 中单词串联的顺序。 
//
// 
//
// 示例 1： 
//
// 输入：
//  s = "barfoothefoobarman",
//  words = ["foo","bar"]
//输出：[0,9]
//解释：
//从索引 0 和 9 开始的子串分别是 "barfoo" 和 "foobar" 。
//输出的顺序不重要, [9,0] 也是有效答案。
// 
//
// 示例 2： 
//
// 输入：
//  s = "wordgoodgoodgoodbestword",
//  words = ["word","good","best","word"]
//输出：[]
// 
// Related Topics 哈希表 双指针 字符串 
// 👍 464 👎 0


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
    vector<int> findSubstring(string s, vector<string> &words) {
        unordered_map<string, int> map;
        int sSize = (int)s.size();
        int fIdx = 0;
        int wordLength = (int) words[0].size();
        int wordCount = (int) words.size();
        int bIdx = wordLength * wordCount;

        for (const auto &string : words) {
            map.emplace(string, 0);
        }

        while (bIdx < sSize) {
            int fIdxTemp = fIdx;
            for (int i = 0; i < wordCount; ++i) {
                string ss = s.substr(fIdxTemp, fIdxTemp + wordLength);

            }


            // 尽可能移动
            bIdx++;
        }
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution solution;
    // 
    return 0;
}