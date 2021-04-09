//
// Created by xuteng on 2021/4/9.
//

#ifndef DATA_STRUCTURE_ARRAYQUEUE_HPP
#define DATA_STRUCTURE_ARRAYQUEUE_HPP

/**
 * 基于数组的队列，按需迁移，自动扩容
 * @tparam T
 */
template<class T>
class ArrayQueue {
private:
    // 数组
    T *data;
    // 数组已用的数量
    int count = 0;
    // 数组容量
    int maxSize;
    // 指向队列头部
    int front;
    // 指向队列尾部
    int back;
public:
    ArrayQueue();
    explicit ArrayQueue(int size);
    ~ArrayQueue();
    // 入列到数组尾部
    bool push(T dataParameter);
    // 出列数组头部元素并删除
    T pop();
    // 数组头部元素，不删除
    T peek();

    void dump();

    int queueSize() {
        return back - front;
    };
    int queueMaxSize() {
        return maxSize;
    }

    static void test();

private:
    // 扩容并返回 新的容量大小
    int expansionSize();
    // 迁移, 但需要避免每次出列后都需要迁移
    void transfer();

};

template<class T>
ArrayQueue<T>::ArrayQueue(): ArrayQueue(10) {}

template<class T>
ArrayQueue<T>::ArrayQueue(int size) {
    data = new T[size];
    this->maxSize = size;
    this->front = 0;
    this->back = -1;
    this->count = 0;
}

template<class T>
ArrayQueue<T>::~ArrayQueue() {
    delete [] data;
    this->maxSize = 0;
    this->count = 0;
    this->front = 0;
    this->back = -1;
}

template<class T>
bool ArrayQueue<T>::push(T dataParameter) {
    transfer();
    this->data[++back] = dataParameter;
    count++;
    cout << "push : " << dataParameter << "\n";
    return true;
}

template<class T>
T ArrayQueue<T>::pop() {
    if(count == 0)
        return NULL;
    T t = data[front++];
    count--;
    cout << "pop : " << t << "\n";
    return t;
}

template<class T>
T ArrayQueue<T>::peek() {
    T t = data[front];
    cout << "peek : " << t << "\n";
    return t;
}

template<class T>
int ArrayQueue<T>::expansionSize() {
    // 如果队列容量已经等于数组容量， 说明需要扩容了
    if(count >= maxSize){
        cout << "expansionSize \n";
        maxSize = (int)maxSize*1.5;
        T *pT = new T[maxSize];
        int i = 0;
        while (i < count){
            *(pT + i) = *(data + i);
            i++;
        }
        delete data;
        front = 0;
        back = count - 1;
        data = pT;
    }
    return maxSize;
}

template<class T>
void ArrayQueue<T>::transfer() {
    int oldSize = maxSize;
    // 如果已经扩容， 也就是迁移了~
    if(oldSize != expansionSize()){
        return;
    }
    // 如果队列尾部指针已经等于了数组尾部指针，说明需要迁移了
    if(back == maxSize - 1){
        cout << "transfer \n";
        int i = 0;
        while (i < maxSize){
            *(data + i++) = data[front++];
        }
        front = 0;
        back = count-1;
    }
}

template<class T>
void ArrayQueue<T>::dump() {
    printf("maxSize【%d】,count【%d】,front【%d】,back【%d】,data【", maxSize, count, front, back);
    int temp = front;
    while (temp <= back){
        T t = data[temp++];
        cout << t;
    }
    printf("】");
    cout << "， array【";
    int i = 0;
    while (i < maxSize){
        cout << data[i++];
    }
    cout << "】\n";
}

template<class T>
void ArrayQueue<T>::test() {
    auto *pQueue = new ArrayQueue<int>(6);
    pQueue->push(0);
    pQueue->push(1);
    pQueue->push(2);
    pQueue->push(3);
    pQueue->push(4);
    pQueue->dump();
    pQueue->peek();
    pQueue->pop();
    pQueue->dump();
    pQueue->push(5);
    pQueue->dump();
    pQueue->push(6);
    pQueue->dump();
    pQueue->push(7);
    pQueue->dump();
    pQueue->push(8);
    pQueue->dump();
    pQueue->push(9);
    pQueue->dump();

    pQueue->pop();
    pQueue->pop();   pQueue->pop();
    pQueue->pop();   pQueue->pop();
    pQueue->pop();   pQueue->pop();
    pQueue->pop();   pQueue->pop();
    pQueue->pop();
    pQueue->dump();

    pQueue->push(9);
    pQueue->push(8);
    pQueue->push(7);
    pQueue->dump();
}

#endif //DATA_STRUCTURE_ARRAYQUEUE_HPP
