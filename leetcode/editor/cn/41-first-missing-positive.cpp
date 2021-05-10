//给你一个未排序的整数数组 nums ，请你找出其中没有出现的最小的正整数。 
//
// 
//
// 进阶：你可以实现时间复杂度为 O(n) 并且只使用常数级别额外空间的解决方案吗？ 
//
// 
//
// 示例 1： 
//
// 
//输入：nums = [1,2,0]
//输出：3
// 
//
// 示例 2： 
//
// 
//输入：nums = [3,4,-1,1]
//输出：2
// 
//
// 示例 3： 
//
// 
//输入：nums = [7,8,9,11,12]
//输出：1
// 
//
// 
//
// 提示： 
//
// 
// 0 <= nums.length <= 300 
// -231 <= nums[i] <= 231 - 1 
// 
// Related Topics 数组 
// 👍 1070 👎 0


#include "iostream"
#include "cassert"
#include "vector"
#include "string"
#include "functional"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int firstMissingPositive(vector<int> &nums) {
        // nums 中可存在重复数据
        // 数组长度是 size, 那么所有正数都依次存在的话，数据范围应该是 [1, size]
        // nums[n] == n + 1;  nums[n-1] == n;
        unsigned long size = nums.size();
        int val;
        for (int i = 0; i < size; ++i) {
            loop:
            val = nums.at(i);
            // 超过size的不需要关注
            if (val > size || val < 1) {
                continue;
            }
            // 不在自己的位置上
            if (val != i + 1) {
                //交换
                int valTemp = nums.at(val - 1);
                if(valTemp == val){
                    continue;
                }
                nums[val - 1] = val;
                nums[i] = valTemp;
                goto loop;
            }
        }

        int res = 1;
        for (int i = 0; i < size; ++i) {
            if(nums[i] == i + 1){
                res = i + 2;
            }else{
                break;
            }
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution solution;
    //
    vector<int> t1 = {3,4,-1,1};
    int i = solution.firstMissingPositive(t1);
    vector<int> t2 = {7,8,9,11,12};
    int i2 = solution.firstMissingPositive(t2);
    return 0;
}