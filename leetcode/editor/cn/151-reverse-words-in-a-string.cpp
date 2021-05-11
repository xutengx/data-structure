//给定一个字符串，逐个翻转字符串中的每个单词。 
//
// 说明： 
//
// 
// 无空格字符构成一个 单词 。 
// 输入字符串可以在前面或者后面包含多余的空格，但是反转后的字符不能包括。 
// 如果两个单词间有多余的空格，将反转后单词间的空格减少到只含一个。 
// 
//
// 
//
// 示例 1： 
//
// 输入："the sky is blue"
//输出："blue is sky the"
// 
//
// 示例 2： 
//
// 输入："  hello world!  "
//输出："world! hello"
//解释：输入字符串可以在前面或者后面包含多余的空格，但是反转后的字符不能包括。
// 
//
// 示例 3： 
//
// 输入："a good   example"
//输出："example good a"
//解释：如果两个单词间有多余的空格，将反转后单词间的空格减少到只含一个。
// 
//
// 示例 4： 
//
// 输入：s = "  Bob    Loves  Alice   "
//输出："Alice Loves Bob"
// 
//
// 示例 5： 
//
// 输入：s = "Alice does not even like bob"
//输出："bob like even not does Alice"
// 
//
// 
//
// 提示： 
//
// 
// 1 <= s.length <= 104 
// s 包含英文大小写字母、数字和空格 ' ' 
// s 中 至少存在一个 单词 
// 
//
// 
// 
//
// 
//
// 进阶： 
//
// 
// 请尝试使用 O(1) 额外空间复杂度的原地解法。 
// 
// Related Topics 字符串 
// 👍 318 👎 0


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
    string reverseWords(string s) {int left = 0, right = s.size() - 1;
        // 去掉字符串开头的空白字符
        while (left <= right && s[left] == ' ') ++left;
        // 去掉字符串末尾的空白字符
        while (left <= right && s[right] == ' ') --right;
        stack<string> words;
        string word;
        while (left <= right) {
            char c = s[left];
            if (word.size() && c == ' ') {
                words.push(word);
                word = "";
            }
            else if (c != ' ') {
                word += c;
            }
            ++left;
        }
        words.push(word);
        string ans;
        while (!words.empty()) {
            ans += words.top();
            words.pop();
            if (!words.empty()) ans += ' ';
        }
        return ans;
    }
//    string reverseWords(string s) {
//            const char *charArr = s.data();
//            unsigned int charSize = s.size();
//            vector<string> stringArr;
//            char *charTempArr = new char[charSize + 1];         // 如果 s 只有一个单词，还需要在他后面补充\0, 所以长度要加一
//            int charTempArrIdx = 0;
//            for (int i = 0; i < charSize; ++i) {
//                char temp = charArr[i];
//                if (temp == ' ') {
//                    if (charTempArrIdx != 0) {
//                        charTempArr[charTempArrIdx] = '\0';
//                        stringArr.emplace_back(charTempArr);
//                        charTempArrIdx = 0;
//                    }
//                } else {
//                    // 一个单词
//                    charTempArr[charTempArrIdx++] = temp;
//                }
//            }
//            // 最后个
//            if (charTempArrIdx != 0) {
//                charTempArr[charTempArrIdx] = '\0';
//                stringArr.emplace_back(charTempArr);
//            }
//
//            unsigned int leftIdx = 0;
//            unsigned int rightIdx = stringArr.size()-1;
//            while (leftIdx < rightIdx){
//                string temp = stringArr.at(rightIdx);
//                stringArr[rightIdx] = stringArr[leftIdx];
//                stringArr[leftIdx] = temp;
//                leftIdx++;
//                rightIdx--;
//            }
//            leftIdx = 0;
//            string res;
//            while (leftIdx < stringArr.size()){
//                res.append(stringArr[leftIdx++]).append(" ");
//            }
//            // 删除最后一个多余的“ ”
//            res.pop_back();
//            return res;
//    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution solution;
    // 
    const string &basicString1 = solution.reverseWords("EPY2giL");
    const string &basicString2 = solution.reverseWords("the sky is blue");
    return 0;
}