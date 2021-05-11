//请你判断一个 9x9 的数独是否有效。只需要 根据以下规则 ，验证已经填入的数字是否有效即可。 
//
// 
// 数字 1-9 在每一行只能出现一次。 
// 数字 1-9 在每一列只能出现一次。 
// 数字 1-9 在每一个以粗实线分隔的 3x3 宫内只能出现一次。（请参考示例图） 
// 
//
// 数独部分空格内已填入了数字，空白格用 '.' 表示。 
//
// 注意： 
//
// 
// 一个有效的数独（部分已被填充）不一定是可解的。 
// 只需要根据以上规则，验证已经填入的数字是否有效即可。 
// 
//
// 
//
// 示例 1： 
//
// 
//输入：board = 
//[['5','3','.','.','7','.','.','.','.']
//,['6','.','.','1','9','5','.','.','.']
//,['.','9','8','.','.','.','.','6','.']
//,['8','.','.','.','6','.','.','.','3']
//,['4','.','.','8','.','3','.','.','1']
//,['7','.','.','.','2','.','.','.','6']
//,['.','6','.','.','.','.','2','8','.']
//,['.','.','.','4','1','9','.','.','5']
//,['.','.','.','.','8','.','.','7','9']]
//输出：true
// 
//
// 示例 2： 
//
// 
//输入：board = 
//[['8','3','.','.','7','.','.','.','.']
//,['6','.','.','1','9','5','.','.','.']
//,['.','9','8','.','.','.','.','6','.']
//,['8','.','.','.','6','.','.','.','3']
//,['4','.','.','8','.','3','.','.','1']
//,['7','.','.','.','2','.','.','.','6']
//,['.','6','.','.','.','.','2','8','.']
//,['.','.','.','4','1','9','.','.','5']
//,['.','.','.','.','8','.','.','7','9']]
//输出：false
//解释：除了第一行的第一个数字从 5 改为 8 以外，空格内其他数字均与 示例1 相同。 但由于位于左上角的 3x3 宫内有两个 8 存在, 因此这个数独是无
//效的。 
//
// 
//
// 提示： 
//
// 
// board.length == 9 
// board[i].length == 9 
// board[i][j] 是一位数字或者 '.' 
// 
// Related Topics 哈希表 
// 👍 520 👎 0


#include "iostream"
#include "cassert"
#include "vector"
#include "string"
#include "functional"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool isValidSudoku(vector<vector<char>> &board) {
        unsigned long oneSize = board.size();
        unsigned long twoSize = board.at(0).size();
        // 以下的 y 表示满足，n 表示不满足，其他 表示未知
        long *cacheRow = new long[9]{0};              // 行
        long *cacheColumn = new long[9]{0};           // 列
        long cacheTian[3][3] = {0};             // 田字

        /**
         * 将char型数，转化为 对应的2进制，对应的十进制
         * eg: char 2  ->  二进制 10 ->  十进制 2
         * eg: char 4  ->  二进制 1000 ->  十进制 8
         */
        function<long(char &)> toInt;
        toInt = [](char &str) -> long {
            if (str == '.') {
                return 0;
            }
            long one = 1;
            return one << ((str - 48) - 1);
        };

        for (int i = 0; i < oneSize; ++i) {
            for (int j = 0; j < twoSize; ++j) {
                long temp = toInt(board[i][j]);
                if (temp == 0) {
                    continue;
                }
                /**
                 * eg: 11001000 | 1000 如果与原值相等，说明 1000 已经存在
                 */
                long i1 = cacheRow[i];
                cacheRow[i] |= temp;
                if (cacheRow[i] == i1) {
                    return false;
                }

                long i2 = cacheColumn[j];
                cacheColumn[j] |= temp;
                if ((cacheColumn[j]) == i2) {
                    return false;
                }

                long i3 = cacheTian[i / 3][j / 3];
                cacheTian[i / 3][j / 3] |= temp;
                if ((cacheTian[i / 3][j / 3]) == i3) {
                    return false;
                }
            }
        }
        return true;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution solution;
    //
    vector<vector<char>> t1;
    t1.push_back({'5', '3', '.', '.', '7', '.', '.', '.', '.'});
    t1.push_back({'6', '.', '.', '1', '9', '5', '.', '.', '.'});
    t1.push_back({'.', '9', '8', '.', '.', '.', '.', '6', '.'});
    t1.push_back({'8', '.', '.', '.', '6', '.', '.', '.', '3'});
    t1.push_back({'4', '.', '.', '8', '.', '3', '.', '.', '1'});
    t1.push_back({'7', '.', '.', '.', '2', '.', '.', '.', '6'});
    t1.push_back({'.', '6', '.', '.', '.', '.', '2', '8', '.'});
    t1.push_back({'.', '.', '.', '4', '1', '9', '.', '.', '5'});
    t1.push_back({'.', '.', '.', '.', '8', '.', '.', '7', '9'});

    bool b = solution.isValidSudoku(t1);
    return 0;
}