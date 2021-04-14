//
// Created by xuteng on 2021/4/12.
//

#ifndef DATA_STRUCTURE_SORTS_HPP
#define DATA_STRUCTURE_SORTS_HPP


template<class T>
class Sorts {
public:
    /**
     * 冒泡排序 (稳定排序 空间O(1) 时间O(n2))
     * 冒泡排序只会操作相邻的两个数据。
     * 每次冒泡操作都会对相邻的两个元素进行比较，看是否满足大小关系要求。如果不满足就让它俩互换。
     * 一次冒泡会让至少一个元素移动到它应该在的位置，重复 n 次，就完成了 n 个数据的排序工作。
     * @param arr
     * @param size
     */
    static void bubble(T *arr, int size);

    /**
     * 插入排序 (稳定排序 空间O(1) 时间O(n2))
     * 首先，我们将数组中的数据分为两个区间，已排序区间和未排序区间。
     * 初始已排序区间只有一个元素，就是数组的第一个元素。
     * 插入算法的核心思想是取未排序区间中的元素，在已排序区间中找到合适的插入位置将其插入，并保证已排序区间数据一直有序。
     * 重复这个过程，直到未排序区间中元素为空，算法结束
     * @param arr
     * @param size
     */
    static void insert(T *arr, int size);

    /**
     * 选择排序 (非稳定排序 空间O(1) 时间O(n2))
     * 区分已排序区间和未排序区间。
     * 选择排序每次会从未排序区间中找到最小的元素，将其放到已排序区间的末尾。
     * @param arr
     * @param size
     */
    static void select(T *arr, int size);

    /**
     * 归并排序 (稳定排序 空间O(n) 时间O(nlog(n))
     * 如果要排序一个数组，我们先把数组从中间分成前后两部分，然后对前后两部分分别排序，再将排好序的两部分合并在一起，这样整个数组就都有序了。
     * @param arr
     * @param size
     */
    static void merge(T *arr, int size);

    /**
     * 快速排序 (不稳定排序 空间O(1) 时间O(nlog(n))
     * 如果要排序数组中下标从 p 到 r 之间的一组数据，我们选择 p 到 r 之间的任意一个数据作为 pivot（分区点）。
     * 我们遍历 p 到 r 之间的数据，将小于 pivot 的放到左边，将大于 pivot 的放到右边，将 pivot 放到中间。
     * 经过这一步骤之后，数组 p 到 r 之间的数据就被分成了三个部分，前面 p 到 q-1 之间都是小于 pivot 的，中间是 pivot，后面的 q+1 到 r 之间是大于 pivot 的。
     * 根据分治、递归的处理思想，我们可以用递归排序下标从 p 到 q-1 之间的数据和下标从 q+1 到 r 之间的数据，直到区间缩小为 1，就说明所有的数据都有序了。
     * @param arr
     * @param size
     */
    static void quick(T *arr, int size);

    /**
     * 桶排序
     * 核心思想是将要排序的数据分到几个有序的桶里，每个桶里的数据再单独进行排序。
     * 桶内排完序之后，再把每个桶里的数据按照顺序依次取出，组成的序列就是有序的了。
     * @param arr
     * @param size
     */
    static void bucket(T *arr, int size);

    static void test();

private:
    // 交换
    static void swap(T *a, T *b);

    // 打印
    static void dump(T *arr, int size);
};

template<class T>
void Sorts<T>::bubble(T *arr, int size) {
    int i = size - 1;
    bool swapFlag = false;
    // 排序的趟数
    while (i > 0) {
        // 本趟排序的遍历元素个数
        for (int j = 0; j < i; j++) {
            if (*(arr + j) > *(arr + j + 1)) {
                swap(arr + j, arr + j + 1);
                swapFlag = true;
            }
        }
        // 本趟数，无数据交换的话，说明已经有序，直接退出
        if (!swapFlag) {
            break;
        }
        i--;
    }
}

template<class T>
void Sorts<T>::insert(T *arr, int size) {
    int i = 1;
    while (i < size) {
        int key = arr[i];/*保存插入的元素数据*/
        int j = i - 1;
        /* i 之前的元素都是有序的，找到比key小的插入到他后面，
		 * 比key大的，需要往后挪一个位置*/
        while ((j >= 0) && (arr[j] > key)) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
        i++;
    }

}

template<class T>
void Sorts<T>::select(T *arr, int size) {
    int min;
    for (int i = 0; i < size; i++) {
        min = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[min]) {
                min = j;
            }
        }
        if (min != i) {
            swap(&arr[min], &arr[i]);
        }
    }
}

template<class T>
void Sorts<T>::merge(T *arr, int size) {
    if (size == 1) {
        return;
    }
    // 拆分
    int oneSize = (int) size / 2;
    int twoSize = size - oneSize;
    T *one = new T[oneSize];
    T *two = new T[twoSize];
    for (int i = 0; i < size; i++) {
        if (i < oneSize) {
            one[i] = arr[i];
        } else {
            two[i - oneSize] = arr[i];
        }
    }
    // 分别排序
    merge(one, oneSize);
    merge(two, twoSize);
    // 合并
    int n = 0, m = 0, k = 0;
    while (n < oneSize && m < twoSize) {
        if (one[n] <= two[m]) {  // 等号 使得排序稳定
            arr[k++] = one[n++];
        } else {
            arr[k++] = two[m++];
        }
    }
    for (; n < oneSize; n++) {
        arr[k++] = one[n++];
    }
    for (; m < twoSize; m++) {
        arr[k++] = two[m++];
    }
}

template<class T>
void Sorts<T>::quick(T *arr, int size) {
    if (size <= 1) {
        return;
    }
    int smallSize = 0;
    int bigSize = 0;
    T pivotValue = arr[0];
    for (int i = 1; i < size; i++) {
//        cout << "sss ------  \n";
//        dump(arr, size);

        if (arr[i] < pivotValue) {
            if (bigSize != 0) {
                swap(&arr[i - bigSize], &arr[i]);
                swap(&arr[smallSize], &arr[i - bigSize]);
            } else {
                swap(&arr[smallSize], &arr[i]);
            }
            smallSize++;
        } else if (arr[i] == pivotValue) {
            smallSize++;
        } else {
            bigSize++;
        }
    }
//    cout << "sss  ========================== \n";
//    dump(arr, size);
    quick(arr, smallSize);
    quick(&arr[smallSize + 1], bigSize);
}

template<class T>
void Sorts<T>::swap(T *a, T *b) {
    T tmp = *a;
    *a = *b;
    *b = tmp;
}

template<class T>
void Sorts<T>::dump(T *arr, int size) {
    int i = 0;
    cout << "dump data [";
    while (i < size) {
        cout << *(arr + i);
        i++;
    }
    cout << "] \n";
}

template<class T>
void Sorts<T>::test() {
    int a1[7] = {9, 2, 1, 4, 5, 0, 9};
    dump(a1, 7);
    bubble(a1, 7);
    dump(a1, 7);


    int a2[7] = {9, 2, 1, 4, 5, 0, 9};
    dump(a2, 7);
    insert(a2, 7);
    dump(a2, 7);

    int a3[7] = {9, 2, 1, 4, 5, 0, 9};
    dump(a3, 7);
    select(a3, 7);
    dump(a3, 7);

    int a4[7] = {9, 2, 1, 4, 5, 0, 9};
    dump(a4, 7);
    merge(a4, 7);
    dump(a4, 7);

    int a5[7] = {9, 2, 1, 4, 5, 0, 9};
    dump(a5, 7);
    quick(a5, 7);
    dump(a5, 7);

    cout << "finish !" << endl;
}


#endif //DATA_STRUCTURE_SORTS_HPP
