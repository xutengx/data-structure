//未知 整数数组 arr 由 n 个非负整数组成。 
//
// 经编码后变为长度为 n - 1 的另一个整数数组 encoded ，其中 encoded[i] = arr[i] XOR arr[i + 1] 。例如，a
//rr = [1,0,2,1] 经编码后得到 encoded = [1,2,3] 。 
//
// 给你编码后的数组 encoded 和原数组 arr 的第一个元素 first（arr[0]）。 
//
// 请解码返回原数组 arr 。可以证明答案存在并且是唯一的。 
//
// 
//
// 示例 1： 
//
// 
//输入：encoded = [1,2,3], first = 1
//输出：[1,0,2,1]
//解释：若 arr = [1,0,2,1] ，那么 first = 1 且 encoded = [1 XOR 0, 0 XOR 2, 2 XOR 1] = [
//1,2,3]
// 
//
// 示例 2： 
//
// 
//输入：encoded = [6,2,7,3], first = 4
//输出：[4,2,0,7,4]
// 
//
// 
//
// 提示： 
//
// 
// 2 <= n <= 104 
// encoded.length == n - 1 
// 0 <= encoded[i] <= 105 
// 0 <= first <= 105 
// 
// Related Topics 位运算 
// 👍 46 👎 0


#include "iostream"
#include "cassert"
#include "vector"
#include "string"
#include "functional"

using namespace std;
/**
 * 异或（eor）是一个数学运算符。它应用于逻辑运算。异或的数学符号为“⊕”，计算机符号为“eor”。其运算法则为：
a⊕b = (¬a ∧ b) ∨ (a ∧¬b)

 * 1. 归零律：a ⊕ a = 0
2. 恒等律：a ⊕ 0 = a
3. 交换律：a ⊕ b = b ⊕ a
4. 结合律：a ⊕b ⊕ c = a ⊕ (b ⊕ c) = (a ⊕ b) ⊕ c;
5. 自反：a ⊕ b ⊕ a = b.
6. d = a ⊕ b ⊕ c 可以推出 a = d ⊕ b ⊕ c.
7.若x是二进制数0101，y是二进制数1011；
 */
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> decode(vector<int> &encoded, int first) {
        vector<int> res;
        unsigned long encodedSize = encoded.size();
        function<void(unsigned long, int)> decodeReal;

        decodeReal = [&encoded, &decodeReal, &res, &encodedSize](unsigned long encodedIdx, int value) {
            if (encodedIdx == encodedSize) {
                return;
            }
            int &encodeValue = encoded.at(encodedIdx);
            int nexValue;
            // encodeValue = value ^ nexValue;
            nexValue = encodeValue ^ value;
            res.push_back(nexValue);
            decodeReal(++encodedIdx, nexValue);
        };
        res.push_back(first);
        decodeReal(0, first);
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution solution;
    //
    vector<int> t1 = {1,2,3};
    const vector<int> &vector = solution.decode(t1,1);
    return 0;
}