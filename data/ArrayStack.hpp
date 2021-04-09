//
// Created by xuteng on 2021/4/7.
//

#ifndef DATA_STRUCTURE_ARRAYSTACK_HPP
#define DATA_STRUCTURE_ARRAYSTACK_HPP

using namespace std;

/**
 * 1）顺序栈的操作：入栈和出栈；
 * 2）采用模板的方法实现存储任意类型的数据
 * 3）采用数组的栈，支持动态扩容，每次扩容1.5 倍，初始栈的大小是 10
 */

template<class T> class ArrayStack {
private:
    int flag;
    int size;
    T *arr;
public:
    ArrayStack();
    explicit ArrayStack(int count);
    ~ArrayStack();
    // 入栈
    bool push(T data);
    // 出栈，并删除栈顶元素
    T pop();
    // 返回栈顶元素，不删除栈顶元素，栈顶指针不变
    T peek();
    int stackSize();
    int stackMaxSize();

    static void test();

private:
    // 扩容并返回 新的容量大小
    int expansionSize();
};

template<class T> ArrayStack<T>::ArrayStack() : ArrayStack(10){}

template<class T> ArrayStack<T>::ArrayStack(int count) {
    flag = 0;
    size = count;
    arr = new T[size];
}

template<class T> ArrayStack<T>::~ArrayStack<T>() {
    flag = 0;
    size = 0;
    if(arr != nullptr){
        delete[] arr;
        arr = nullptr;
    }
}

template<class T> bool ArrayStack<T>::push(T data) {
    expansionSize();
    arr[flag++] = data;
    return true;
}

template<class T> T ArrayStack<T>::pop() {
    return arr[flag--];
}
template<class T> T ArrayStack<T>::peek() {
    return arr[flag];
}
template<class T> int ArrayStack<T>::stackSize() {
    return flag;
}
template<class T> int ArrayStack<T>::stackMaxSize() {
    return size;
}

template<class T> int ArrayStack<T>::expansionSize() {
    if(flag < size-1){
        return size;
    }
    size = (int )size * 1.5;
    auto *newArray = new T[size];
    for (int i = 0 ; i <= flag; i++){
//        newArray[i] = arr[i];
        *(newArray + i) =  *(arr + i);
    }
    delete [] arr;
    arr = newArray;
    return size;
}

template<class T>  void ArrayStack<T>::test() {

}

#endif //DATA_STRUCTURE_ARRAYSTACK_HPP
