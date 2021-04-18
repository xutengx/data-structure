//
// Created by xuteng on 2021/4/17.
//

#ifndef DATA_STRUCTURE_SEARCH_HPP
#define DATA_STRUCTURE_SEARCH_HPP

#include <cassert>
#include <functional>

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

            if (searchValue > arr[midIdx]) {
                return binaryReal(arr, midIdx + 1, highIdx, searchValue);
            } else  if (searchValue < arr[midIdx]) {
                return binaryReal(arr, lowIdx, midIdx - 1, searchValue);
            } else {
                return midIdx;
            }
        };

        return binaryReal(arr, 0, size - 1, searchValue);
    }

    /**
     * 二分查找, 查找第一个值等于给定值的元素
     * @param arr 已有序的数组, 且可以有重复元素
     * @param size 数组大小
     * @param searchValue 要查找的元素
     * @return 下标
     */
    static int binaryFirstValue(const int *arr, int size, int searchValue) {
        // 声明匿名函数，得到函数指针
        function<int(const int *, int, int, int)> binaryReal;
        // 递归
        binaryReal = [&binaryReal](const int *arr, int lowIdx, int highIdx, int searchValue) {
            if (lowIdx > highIdx) {
                return -1;
            }
            // 防止溢出
            int midIdx = (int) (lowIdx + ((highIdx - lowIdx) >> 1));

            if (searchValue > arr[midIdx]) {
                return binaryReal(arr, midIdx + 1, highIdx, searchValue);
            } else  if (searchValue < arr[midIdx]) {
                small :
                return binaryReal(arr, lowIdx, midIdx - 1, searchValue);
            } else {
                // 注意, 相等的值, 不一定是第一个
                // 1. 是第一个那么一定是, 2. 前一个的值不是目标值, 那么也行
                if(midIdx == 0 || arr[midIdx - 1] != searchValue){
                    return midIdx;
                }
                // 在较小的区间在区找
                else{
                    goto small;
                }
            }
        };
        return binaryReal(arr, 0, size - 1, searchValue);
    }

    /**
     * 二分查找, 查找最后一个值等于给定值的元素
     * @param arr 已有序的数组, 且可以有重复元素
     * @param size 数组大小
     * @param searchValue 要查找的元素
     * @return 下标
     */
    static int binaryLastValue(const int *arr, int size, int searchValue) {
        // 声明匿名函数，得到函数指针
        function<int(const int *, int, int, int)> binaryReal;
        // 递归
        binaryReal = [&binaryReal, &size](const int *arr, int lowIdx, int highIdx, int searchValue) {
            if (lowIdx > highIdx) {
                return -1;
            }
            // 防止溢出
            int midIdx = (int) (lowIdx + ((highIdx - lowIdx) >> 1));

            if (searchValue > arr[midIdx]) {
                big :
                return binaryReal(arr, midIdx + 1, highIdx, searchValue);
            } else  if (searchValue < arr[midIdx]) {
                small :
                return binaryReal(arr, lowIdx, midIdx - 1, searchValue);
            } else {
                // 注意, 相等的值, 不一定是最后个
                // 1. 是最后个那么一定是, 2. 后一个的值不是目标值, 那么也行
                if(midIdx == size -1 || arr[midIdx + 1] != searchValue){
                    return midIdx;
                }
                // 在较大的区间在区找
                else{
                    goto big;
                }
            }
        };
        return binaryReal(arr, 0, size - 1, searchValue);
    }

    /**
     * 二分查找, 查找第一个大于等于给定值的元素
     * 比如，数组中存储的这样一个序列：3，4，6，7，10。如果查找第一个大于等于 5 的元素，那就是 6。
     * @param arr 已有序的数组, 且可以有重复元素
     * @param size 数组大小
     * @param searchValue 要查找的元素
     * @return 下标
     */
    static int binaryFirstBiggerValue(const int *arr, int size, int searchValue) {
        // 声明匿名函数，得到函数指针
        function<int(const int *, int, int, int)> binaryReal;
        // 递归
        binaryReal = [&binaryReal](const int *arr, int lowIdx, int highIdx, int searchValue) {
            if (lowIdx > highIdx) {
                return -1;
            }
            // 防止溢出
            int midIdx = (int) (lowIdx + ((highIdx - lowIdx) >> 1));

            if (searchValue > arr[midIdx]) {
                if(searchValue <= arr[midIdx + 1]){
                    return midIdx + 1;
                }
                big :
                return binaryReal(arr, midIdx + 1, highIdx, searchValue);
            } else  if (searchValue < arr[midIdx]) {
                small :
                return binaryReal(arr, lowIdx, midIdx - 1, searchValue);
            } else {
                // 1. 第一个值就相等了,那么一定是; 2. 前一个就不等于(必是小于)了,那么也一定是
                if(midIdx == 0 || arr[midIdx - 1] != searchValue){
                    return midIdx;
                }
                // 在较小的区间再找
                else{
                    goto small;
                }
            }
        };
        return binaryReal(arr, 0, size - 1, searchValue);
    }



    /**
     * 二分查找, 查找最后一个小于等于给定值的元素
     * 比如，数组中存储了这样一组数据：3，5，6，8，9，10。最后一个小于等于 7 的元素就是 6。
     * @param arr 已有序的数组, 且可以有重复元素
     * @param size 数组大小
     * @param searchValue 要查找的元素
     * @return 下标
     */
    static int binaryLastSmallValue(const int *arr, int size, int searchValue) {
        // 声明匿名函数，得到函数指针
        function<int(const int *, int, int, int)> binaryReal;
        // 递归
        binaryReal = [&binaryReal, &size](const int *arr, int lowIdx, int highIdx, int searchValue) {
            if (lowIdx > highIdx) {
                return -1;
            }
            // 防止溢出
            int midIdx = (int) (lowIdx + ((highIdx - lowIdx) >> 1));

            if (searchValue > arr[midIdx]) {
                big :
                return binaryReal(arr, midIdx + 1, highIdx, searchValue);
            } else  if (searchValue < arr[midIdx]) {
                if(searchValue > arr[midIdx - 1]){
                    return midIdx - 1;
                }
                small :
                return binaryReal(arr, lowIdx, midIdx - 1, searchValue);
            } else {
                if(midIdx == size - 1 || arr[midIdx + 1] != searchValue){
                    return midIdx;
                }
                // 在较大的区间再找
                else{
                    goto big;
                }
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


    int a2[] = {1, 2, 3, 3, 3, 6, 6, 8, 9};
    assert(binaryFirstValue(a2, 9, 1) == 0);
    assert(binaryFirstValue(a2, 9, 3) == 2);
    assert(binaryFirstValue(a2, 9, 6) == 5);
    assert(binaryFirstValue(a2, 9, 9) == 8);

    assert(binaryLastValue(a2, 9, 1) == 0);
    assert(binaryLastValue(a2, 9, 3) == 4);
    assert(binaryLastValue(a2, 9, 6) == 6);
    assert(binaryLastValue(a2, 9, 9) == 8);

    assert(binaryFirstBiggerValue(a2, 9, 1) == 0);
    assert(binaryFirstBiggerValue(a2, 9, 5) == 5);
    assert(binaryFirstBiggerValue(a2, 9, 6) == 5);
    assert(binaryFirstBiggerValue(a2, 9, 7) == 7);
    assert(binaryFirstBiggerValue(a2, 9, 8) == 7);
    assert(binaryFirstBiggerValue(a2, 9, 9) == 8);

    assert(binaryLastSmallValue(a2, 9, 1) == 0);
    assert(binaryLastSmallValue(a2, 9, 5) == 4);
    assert(binaryLastSmallValue(a2, 9, 6) == 6);
    assert(binaryLastSmallValue(a2, 9, 7) == 6);
    assert(binaryLastSmallValue(a2, 9, 8) == 7);
    assert(binaryLastSmallValue(a2, 9, 9) == 8);

    cout << "finish !" << endl;

}

#endif //DATA_STRUCTURE_SEARCH_HPP
