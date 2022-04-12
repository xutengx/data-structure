//给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？请你找出所有和为 0 且不重
//复的三元组。 
//
// 注意：答案中不可以包含重复的三元组。 
//
// 
//
// 示例 1： 
//
// 
//输入：nums = [-1,0,1,2,-1,-4]
//输出：[[-1,-1,2],[-1,0,1]]
// 
//
// 示例 2： 
//
// 
//输入：nums = []
//输出：[]
// 
//
// 示例 3： 
//
// 
//输入：nums = [0]
//输出：[]
// 
//
// 
//
// 提示： 
//
// 
// 0 <= nums.length <= 3000 
// -105 <= nums[i] <= 105 
// 
// Related Topics 数组 双指针 
// 👍 3313 👎 0


#include <algorithm>
#include "iostream"
#include "cassert"
#include "vector"
#include "string"
#include "functional"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<vector<int>> threeSum(vector<int> &nums) {
        // 先排序
        sort(nums.begin(), nums.end());

        vector<vector<int>> res;
        unsigned long numSize = nums.size();
        if (numSize < 3) {
            return res;
        }
        for (int i = 0; i < numSize - 2; ++i) {
            int first = nums.at(i);
            if (i > 0 && nums.at(i - 1) == first) {
                continue;
            }
            int second, third;
            unsigned int leftIdx = i + 1;
            unsigned int rightIdx = numSize - 1;
            while (leftIdx < rightIdx) {
                second = nums.at(leftIdx);
                third = nums.at(rightIdx);
//                if (second == third) {
//                    break;
//                } else
                if (leftIdx - 1 > i && nums.at(leftIdx - 1) == second) {
                    leftIdx++;
                    continue;
                } else if (rightIdx + 1 < numSize && nums.at(rightIdx + 1) == third) {
                    rightIdx--;
                    continue;
                }

                int value = first + second + third;
                if (value == 0) {
                    res.push_back({first, second, third});
                    leftIdx++;
                    rightIdx--;
                } else if (value < 0) {
                    if (third < 0) {
                        break;
                    }
                    leftIdx++;
                } else if (value > 0) {
                    if (second + first > 0) {
                        break;
                    }
                    rightIdx--;
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

    vector<int> t1 = {34,55,79,28,46,33,2,48,31,-3,84,71,52,-3,93,15,21,-43,57,-6,86,56,94,74,83,-14,28,-66,46,-49,62,-11,43,65,77,12,47,61,26,1,13,29,55,-82,76,26,15,-29,36,-29,10,-70,69,17,49};
    const vector<vector<int>> &r1 = solution.threeSum(t1);
    return 0;
}