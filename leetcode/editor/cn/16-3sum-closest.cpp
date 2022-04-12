//给你一个长度为 n 的整数数组 nums 和 一个目标值 target。请你从 nums 中选出三个整数，使它们的和与 target 最接近。 
//
// 返回这三个数的和。 
//
// 假定每组输入只存在恰好一个解。 
//
// 
//
// 示例 1： 
//
// 
//输入：nums = [-1,2,1,-4], target = 1
//输出：2
//解释：与 target 最接近的和是 2 (-1 + 2 + 1 = 2) 。
// 
//
// 示例 2： 
//
// 
//输入：nums = [0,0,0], target = 1
//输出：0
// 
//
// 
//
// 提示： 
//
// 
// 3 <= nums.length <= 1000 
// -1000 <= nums[i] <= 1000 
// -10⁴ <= target <= 10⁴ 
// 
// Related Topics 数组 双指针 排序 👍 1050 👎 0

#include "algorithm"
#include "functional"
#include "vector"
#include "assert.h"
#include "string"
#include "iostream"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:

    /**
     * 时间复杂度 O(n^2)
     */
    int threeSumClosest(vector<int> &nums, int target) {
        // 先排序
        sort(nums.begin(), nums.end());

        // 数据大小
        int length = nums.size();

        // 当前值
        int current = nums[0] + nums[1] + nums[2];

        // 结果值
        int res = current;

        // 当前的差值
        int difference = abs(current - target);

        // 中心指针 index
        for (int index = 1; index < length - 1; ++index) {

            // 左指针 leftIndex
            int leftIndex = index - 1;

            // 右指针 rightIndex
            int rightIndex = index + 1;

            bool flag;
            do {
                // 当前值
                current = nums[leftIndex] + nums[index] + nums[rightIndex];

                // 萌出了结果
                if (current == target) {
                    return current;
                }

                // 如果更接近, 更新相关值
                if (abs(current - target) < difference) {
                    difference = abs(current - target);
                    res = current;
                }

                // 确定指针的移动
                if (current < target && rightIndex < length - 1) {
                    rightIndex++;
                    flag = true;
                } else if (current > target && leftIndex > 0) {
                    leftIndex--;
                    flag = true;
                } else {
                    flag = false;
                }
            } while (flag);
        }
        return res;
    }



    /**
     * 时间复杂度 O(n^3)
     */
//    int threeSumClosest_bak(vector<int> &nums, int target) {
//        // 先排序
//        sort(nums.begin(), nums.end());
//
//        // 数据大小
//        int length = nums.size();
//
//        // 当前值
//        int current = nums[0] + nums[1] + nums[2];
//
//        // 结果值
//        int res = current;
//
//        // 当前的差值
//        int difference = abs(current - target);
//
//        // 初始化指针
//        for (int index0 = 0; index0 < length - 2; ++index0) {
//            for (int index1 = index0 + 1; index1 < length - 1; ++index1) {
//                for (int index2 = index1 + 1; index2 < length; ++index2) {
//
//                    // 当前结果值
//                    current = nums[index0] + nums[index1] + nums[index2];
//                    // 当前的差值更接近, 那么更新相关结论
//                    if(abs(current - target) < difference){
//                        difference = abs(current - target);
//                        res = current;
//                    }
//                    // 目前已经在远离目标了
//                    else if( current - target > 0 ){
//                        break;
//                    }
//
//                }
//            }
//        }
//        return res;
//    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution solution;
    //
    vector<int> v = {-3,0,1,2};
    cout << solution.threeSumClosest(v, 1);

    return 0;
}