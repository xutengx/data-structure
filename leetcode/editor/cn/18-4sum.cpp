//给你一个由 n 个整数组成的数组 nums ，和一个目标值 target 。请你找出并返回满足下述全部条件且不重复的四元组 [nums[a], nums[
//b], nums[c], nums[d]] （若两个四元组元素一一对应，则认为两个四元组重复）： 
//
// 
// 0 <= a, b, c, d < n 
// a、b、c 和 d 互不相同 
// nums[a] + nums[b] + nums[c] + nums[d] == target 
// 
//
// 你可以按 任意顺序 返回答案 。 
//
// 
//
// 示例 1： 
//
// 
//输入：nums = [1,0,-1,0,-2,2], target = 0
//输出：[[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
// 
//
// 示例 2： 
//
// 
//输入：nums = [2,2,2,2,2], target = 8
//输出：[[2,2,2,2]]
// 
//
// 
//
// 提示： 
//
// 
// 1 <= nums.length <= 200 
// -10⁹ <= nums[i] <= 10⁹ 
// -10⁹ <= target <= 10⁹ 
// 
// Related Topics 数组 双指针 排序 👍 1207 👎 0


#include <algorithm>
#include "functional"
#include "vector"
#include "assert.h"
#include "string"
#include "iostream"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target) {
        // 结果
        vector<vector<int>> res;
        // 排序
        sort(nums.begin(), nums.end());
        int size = nums.size();

        // 设定一级指针
        for (int firstLevelIndex = 0; firstLevelIndex < size - 3; firstLevelIndex++) {
            // 跳过重复的答案
            if (firstLevelIndex > 0 && nums[firstLevelIndex] == nums[firstLevelIndex - 1]) {
                continue;
            }
            // 剪枝: 最小的情况 都大于 target , 就不会存在答案啦
            if ((long)nums[firstLevelIndex] + nums[firstLevelIndex + 1] + nums[firstLevelIndex + 2] +
                nums[firstLevelIndex + 3] > target) {
                return res;
            }
            // 剪枝: 最大的情况 都小于 target , 就不会存在答案啦
            // 下次循环再看看
            if ((long)nums[firstLevelIndex] + nums[size - 3] + nums[size - 2] + nums[size - 1] < target) {
                continue;
            }

            // 设定二级指针
            for (int secondLevelIndex = firstLevelIndex + 1; secondLevelIndex < size - 2; secondLevelIndex++) {
                // 跳过重复的答案
                if (secondLevelIndex > firstLevelIndex + 1 && nums[secondLevelIndex] == nums[secondLevelIndex - 1]) {
                    continue;
                }

                // 前两个指针对应的值的合
                long sumFirstAndSecond = (long)nums[firstLevelIndex] + nums[secondLevelIndex];

                // 剪枝: 最小的情况 都大于 target , 就不会存在答案啦
                if ((long)sumFirstAndSecond + nums[secondLevelIndex + 1] + nums[secondLevelIndex + 2] > target) {
                    break;
                }

                // 剪枝: 最大的情况 都小于 target , 就不会存在答案啦
                // 下次循环再看看
                if ((long)sumFirstAndSecond + nums[size - 2] + nums[size - 1] < target) {
                    continue;
                }

                // 定义 左右指针
                int leftIndex = secondLevelIndex + 1, rightIndex = size - 1;

                while (leftIndex < rightIndex) {
                    // 当前sum
                    long currentSum = sumFirstAndSecond + nums[leftIndex] + nums[rightIndex];
                    // 命中结果, 加入结果集
                    if (currentSum == target) {
                        // 构造结果
                        vector<int> innerRes = {nums[firstLevelIndex], nums[secondLevelIndex], nums[leftIndex],
                                                nums[rightIndex]};
                        // 加入结果
                        res.emplace_back(innerRes);

                        do {
                            ++leftIndex;
                        }
                            // 跳过重复的答案
                        while (leftIndex < rightIndex && nums[leftIndex] == nums[leftIndex - 1]);
                        do {
                            --rightIndex;
                        }
                            // 跳过重复的答案
                        while (leftIndex < rightIndex && nums[rightIndex] == nums[rightIndex + 1]);
                    }
                        // 右指针 右移
                    else if (currentSum < target) {
                        do {
                            ++leftIndex;
                        }
                            // 跳过重复的答案
                        while (leftIndex < rightIndex && nums[leftIndex] == nums[leftIndex - 1]);
                    }
                        // 左指针 左移
                    else if (currentSum > target) {
                        do {
                            --rightIndex;
                        }
                            // 跳过重复的答案
                        while (leftIndex < rightIndex && nums[rightIndex] == nums[rightIndex + 1]);
                    }
                }

            }
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution solution;
    //

//    vector<int> nums = {-2, -1, -1, 1, 1, 2, 2};
//    const vector<vector<int>> &vector = solution.fourSum(nums, 0);
    vector<int> nums = {1000000000,1000000000,1000000000,1000000000};
    const vector<vector<int>> &vector = solution.fourSum(nums, 0);

    for (const auto &list: vector) {
        cout << "[";
        for (const auto &item: list) {
            cout << item << " , ";
        }
        cout << "] \n";
    }

    return 0;
}