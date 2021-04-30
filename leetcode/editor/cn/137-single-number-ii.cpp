//给你一个整数数组 nums ，除某个元素仅出现 一次 外，其余每个元素都恰出现 三次 。请你找出并返回那个只出现了一次的元素。 
//
// 
//
// 示例 1： 
//
// 
//输入：nums = [2,2,3,2]
//输出：3
// 
//
// 示例 2： 
//
// 
//输入：nums = [0,1,0,1,0,1,99]
//输出：99
// 
//
// 
//
// 提示： 
//
// 
// 1 <= nums.length <= 3 * 104 
// -231 <= nums[i] <= 231 - 1 
// nums 中，除某个元素仅出现 一次 外，其余每个元素都恰出现 三次 
// 
//
// 
//
// 进阶：你的算法应该具有线性时间复杂度。 你可以不使用额外空间来实现吗？ 
// Related Topics 位运算 
// 👍 584 👎 0


#include "iostream"
#include "cassert"
#include "vector"
#include "string"
#include "functional"

using namespace std;
 
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int target = 0;
        // unsigned int = 0 - 2的32次方
        // int = -2的31次方 到 2的31次方
        // 从后到前的前31位是表示正整数, 需要特殊处理 i=32的情况
        // 但是题目中 nums中的每个值范围 -231 <= nums[i] <= 231 - 1， 所以就偷懒了
        for(int i = 0 ; i < 32 ; i++){
            // 当前位
            int total = 0;
            for(int num : nums){
                // 对于会重复3次的位， 无论重复个多少个3次，total的值都只会是3的倍数，如果不是3的倍数(有余数)说明此位存在没有重复3次的情况
                // 即 目标值在此位上的2进制不为0
                total += ((num >> i) & 1);
            }
            if((total % 3) != 0){
                target |= (1 << i);
            }
        }
        return target;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main(){
    Solution solution;
    // 
    return 0;
}