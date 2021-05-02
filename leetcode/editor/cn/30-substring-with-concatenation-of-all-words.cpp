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
        int sSize = (int) s.size();
        int wordLength = (int) words[0].size();
        int wordCount = (int) words.size();
        //
        vector<int> res;

        // 字符出现次数，记录到map
        unordered_map<string, int> map;
        for (const auto &string : words) {
            map[string]++;
        }

        // 每个窗口中的 字符出现次数，记录到map
        vector<unordered_map<string, int>> mapLst(wordLength);
        // 多个滑动窗口，避免遗漏
        for (int i = 0; i < wordLength; ++i) {
            int fIdx = i;                                   // 当前窗口的前指针
            int bIdx = fIdx + wordLength * wordCount;       // 当前窗口的末指针
            while (bIdx <= sSize) {
                // 拆分单词
                int fIdxTemp = fIdx;
                while (fIdxTemp + wordLength <= bIdx) {
                    string ss = s.substr(fIdxTemp, wordLength);
                    // 尽量多的滑动，如果不存在，或者过多
                    if (!map.count(ss) || ++(mapLst[i][ss]) > map.at(ss)) {
                        goto rBreak;
                    }
                    fIdxTemp += wordLength;
                }
                // 记录响应
                res.push_back(fIdx);

                rBreak:
                // 清空当前map
                mapLst[i].clear();
                // 滑动单词的长度
                fIdx += wordLength;
                bIdx += wordLength;
            }
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution solution;
    //
    vector<string> f1;
    f1.emplace_back("word");
    f1.emplace_back("good");
    f1.emplace_back("best");
    f1.emplace_back("good");
    auto vector1 = solution.findSubstring("wordgoodgoodgoodbestword", f1);

    vector<string> f2;
    f2.emplace_back("foo");
    f2.emplace_back("bar");
    auto vector2 = solution.findSubstring("barfoothefoobarman", f2);

    return 0;
}