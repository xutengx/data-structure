//给定两个大小分别为 m 和 n 的正序（从小到大）数组 nums1 和 nums2。请你找出并返回这两个正序数组的 中位数 。 
//
// 
//
// 示例 1： 
//
// 
//输入：nums1 = [1,3], nums2 = [2]
//输出：2.00000
//解释：合并数组 = [1,2,3] ，中位数 2
// 
//
// 示例 2： 
//
// 
//输入：nums1 = [1,2], nums2 = [3,4]
//输出：2.50000
//解释：合并数组 = [1,2,3,4] ，中位数 (2 + 3) / 2 = 2.5
// 
//
// 示例 3： 
//
// 
//输入：nums1 = [0,0], nums2 = [0,0]
//输出：0.00000
// 
//
// 示例 4： 
//
// 
//输入：nums1 = [], nums2 = [1]
//输出：1.00000
// 
//
// 示例 5： 
//
// 
//输入：nums1 = [2], nums2 = []
//输出：2.00000
// 
//
// 
//
// 提示： 
//
// 
// nums1.length == m 
// nums2.length == n 
// 0 <= m <= 1000 
// 0 <= n <= 1000 
// 1 <= m + n <= 2000 
// -106 <= nums1[i], nums2[i] <= 106 
// 
//
// 
//
// 进阶：你能设计一个时间复杂度为 O(log (m+n)) 的算法解决此问题吗？ 
// Related Topics 数组 二分查找 分治算法 
// 👍 4038 👎 0


#include "functional"
#include "vector"
#include "assert.h"
#include "iostream"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        unsigned long long int numsOneSize = nums1.size();
        unsigned long long int numsTwoSize = nums2.size();
        if (numsOneSize == 0 && numsTwoSize == 0) {
            return 0;
        }
        // 是偶数
        bool ou = (numsOneSize % 2 + numsTwoSize % 2) % 2 == 0;

        unsigned long long int y;
        if (numsOneSize > numsTwoSize) {
            y = (int) ((numsOneSize - numsTwoSize) >> 1) + numsTwoSize + 1;
        } else {
            y = (int) ((numsTwoSize - numsOneSize) >> 1) + numsOneSize + 1;
        }

        int *arr = new int[y];
        // 有序数列合并 begin
        int n1, n2, n;
        n1 = n2 = n = 0;
        while (n1 < numsOneSize && n2 < numsTwoSize) {
            if (nums1[n1] <= nums2[n2]) {
                arr[n++] = nums1[n1++];
            } else {
                arr[n++] = nums2[n2++];
            }
            if (n == y) {
                break;
            }
        }
        while (n1 < numsOneSize && n != y) {
            arr[n++] = nums1[n1++];
        }
        while (n2 < numsTwoSize && n != y) {
            arr[n++] = nums2[n2++];
        }
        // 有序数列合并 end

        for(int i = 0 ; i < y; i ++){
            cout << "----" << arr[i];
        }
        cout << "\n";

        // 奇偶判断
        if (y == 1) {
            return arr[y - 1];
        }
        return ou ? ((double)arr[y - 2] + arr[y - 1])/2 : arr[y - 1];
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main(){
    Solution solution;
    //
    vector<int> one;
    one.push_back(1);
    one.push_back(2);
    vector<int> two;
    two.push_back(3);
    two.push_back(4);
    double d = solution.findMedianSortedArrays(one, two);
    cout << d ;
    return 0;
}