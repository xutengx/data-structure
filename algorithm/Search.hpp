//
// Created by xuteng on 2021/4/17.
//

#ifndef DATA_STRUCTURE_SEARCH_HPP
#define DATA_STRUCTURE_SEARCH_HPP

#include <cassert>

class Search {
public:

    static void test();

    /**
     * 二分查找
     * @param arr 已有序的数组, 且没有重复元素
     * @param size 数组大小
     * @param searchValue 要查找的元素
     * @return 下标
     */
    static int binary(const int *arr, int size, int searchValue) {

        // 声明匿名函数，得到函数指针
        function<int(const int *, int, int, int)> binaryReal;

        // 递归
        binaryReal = [&binaryReal](const int *arr, int lowIdx, int highIdx, int searchValue) {
            if (lowIdx > highIdx) {
                return -1;
            }

            // 防止溢出
            int midIdx = (int) (lowIdx + ((highIdx - lowIdx) >> 1));

            if (searchValue == arr[midIdx]) {
                return midIdx;
            } else if (searchValue > arr[midIdx]) {
                return binaryReal(arr, midIdx + 1, highIdx, searchValue);
            } else {
                return binaryReal(arr, lowIdx, midIdx - 1, searchValue);
            }
        };

        return binaryReal(arr, 0, size - 1, searchValue);
    }

};

void Search::test() {
    int a1[] = {1, 2, 3, 4, 5, 6, 7};
    assert(binary(a1, 7, 3) == 2);
    assert(binary(a1, 7, 1) == 0);
    assert(binary(a1, 7, 0) == -1);
    assert(binary(a1, 7, 7) == 6);
    assert(binary(a1, 7, 8) == -1);

    cout << "finish !" << endl;

}

#endif //DATA_STRUCTURE_SEARCH_HPP
