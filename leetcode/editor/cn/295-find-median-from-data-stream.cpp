//中位数是有序列表中间的数。如果列表长度是偶数，中位数则是中间两个数的平均值。 
//
// 例如， 
//
// [2,3,4] 的中位数是 3 
//
// [2,3] 的中位数是 (2 + 3) / 2 = 2.5 
//
// 设计一个支持以下两种操作的数据结构： 
//
// 
// void addNum(int num) - 从数据流中添加一个整数到数据结构中。 
// double findMedian() - 返回目前所有元素的中位数。 
// 
//
// 示例： 
//
// addNum(1)
//addNum(2)
//findMedian() -> 1.5
//addNum(3) 
//findMedian() -> 2 
//
// 进阶: 
//
// 
// 如果数据流中所有整数都在 0 到 100 范围内，你将如何优化你的算法？ 
// 如果数据流中 99% 的整数都在 0 到 100 范围内，你将如何优化你的算法？ 
// 
// Related Topics 堆 设计 
// 👍 411 👎 0


#include "iostream"
#include "cassert"
#include "vector"
#include "string"
#include "functional"
#include "queue"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class MedianFinder {
    // 大顶推
    priority_queue<int> bigHeap;
    // 小顶堆
    priority_queue<int, vector<int>, greater<int>> smallHeap;

public:

    void addNum(int num) {
        bigHeap.push(num);
        smallHeap.push(bigHeap.top());
        bigHeap.pop();

        if (bigHeap.size() < smallHeap.size()) {
            bigHeap.push(smallHeap.top());
            smallHeap.pop();
        }
    }

    double findMedian() {
        return bigHeap.size() > smallHeap.size() ? (double) bigHeap.top() : (bigHeap.top() + smallHeap.top()) * 0.5;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution solution;
    // 
    return 0;
}