//
// Created by xuteng on 2021/4/12.
//

#ifndef DATA_STRUCTURE_SORTS_HPP
#define DATA_STRUCTURE_SORTS_HPP


template<class T>
class Sorts{
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
    while (i > 0){
        // 本趟排序的遍历元素个数
        for(int j = 0; j < i ; j++){
            if(*(arr + j) > *(arr + j + 1)){
                swap(arr + j, arr + j + 1);
                swapFlag = true;
            }
        }
        // 本趟数，无数据交换的话，说明已经有序，直接退出
        if(!swapFlag){
            break;
        }
        i--;
    }
}

template<class T>
void Sorts<T>::insert(T *arr, int size) {
    int i = 1;
    while (i < size){
        int key = arr[i];/*保存插入的元素数据*/
        int j = i - 1;
        /* i 之前的元素都是有序的，找到比key小的插入到他后面，
		 * 比key大的，需要往后挪一个位置*/
        while((j >= 0) && (arr[j] > key))
        {
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
    for(int i = 0; i < size ; i ++ ){
        min = i;
        for(int j = i + 1; j < size ; j ++ ){
            if (arr[j] < arr[min]){
                min = j;
            }
        }
        if(min != i){
            swap(&arr[min], &arr[i]);
        }
    }
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
    while (i < size){
        cout << *(arr + i);
        i++;
    }
    cout << "] \n";
}

template<class T>
void Sorts<T>::test() {
    int a1[5] = {9, 2, 1, 4, 5};
    dump(a1, 5);
    bubble(a1, 5);
    dump(a1, 5);


    int a2[5] = {9, 2, 1, 4, 5};
    dump(a2, 5);
    insert(a2, 5);
    dump(a2, 5);

    int a3[5] = {9, 2, 1, 4, 5};
    dump(a3, 5);
    select(a3, 5);
    dump(a3, 5);

}


#endif //DATA_STRUCTURE_SORTS_HPP
