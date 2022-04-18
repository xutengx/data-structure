//给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。答案可以按 任意顺序 返回。 
//
// 给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。 
//
// 
//
// 
//
// 示例 1： 
//
// 
//输入：digits = "23"
//输出：["ad","ae","af","bd","be","bf","cd","ce","cf"]
// 
//
// 示例 2： 
//
// 
//输入：digits = ""
//输出：[]
// 
//
// 示例 3： 
//
// 
//输入：digits = "2"
//输出：["a","b","c"]
// 
//
// 
//
// 提示： 
//
// 
// 0 <= digits.length <= 4 
// digits[i] 是范围 ['2', '9'] 的一个数字。 
// 
// Related Topics 哈希表 字符串 回溯 👍 1852 👎 0


#include "functional"
#include "vector"
#include "assert.h"
#include "string"
#include "iostream"
#include "unordered_map"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    /**
     * 题目的意思是, 手机的9宫格的输入法, 按下的数字键, 对应多少种字符串
     * |      | abc | def    |
     * | ghi  | jkl | nmo   |
     * | pqrs | tuv | wxyz |
     *
     * @param digits
     * @return
     */
    vector<string> letterCombinations(string digits) {
        // 结果对象
        vector<string> res;
        // 构建映射关系
        auto *map = new unordered_map<char, vector<char>>();
        map->insert({
                            {'2', {'a', 'b', 'c'}},
                            {'3', {'d', 'e', 'f'}},
                            {'4', {'g', 'h', 'i'}},
                            {'5', {'j', 'k', 'l'}},
                            {'6', {'m', 'n', 'o'}},
                            {'7', {'p', 'q', 'r', 's'}},
                            {'8', {'t', 'u', 'v'}},
                            {'9', {'w', 'x', 'y', 'z'}}
                    });
        // 循环数字
        for (const auto &item: digits) {
            // 找到数字对应的字母列表
            auto list = map->at(item);
            vector<string> temp;
            // 循环字母列表
            for (const auto &c: list) {
                // 如果是第一次,那么就简单的转化下类型之后加入结果
                if (res.empty()) {
                    // char 转化 string   使用 string(length, char)
                    temp.emplace_back(string(1, c));
                } else
                    // 将之前的每个已经存在的结果, 分别拼接上当前的字母, 在加入新的临时结果
                    for (const auto &old: res) {
                        temp.emplace_back(old + c);
                    }
            }
            // 新的临时结果 进行覆盖
            res = temp;
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution solution;
    //

    const vector<string> &vector = solution.letterCombinations("23");

    for (const auto &item : vector){
        cout << item << "\n";
    }
    return 0;
}