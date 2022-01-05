//
// Created by xuteng on 2021/4/26.
//

#ifndef DATA_STRUCTURE_GRAPH_HPP
#define DATA_STRUCTURE_GRAPH_HPP

#include "LinkedListQueue.hpp"
#include "functional"

/**
 * 图
 *
 * 图最直观的一种存储方法就是，邻接矩阵（Adjacency Matrix）。
 *
 * 邻接矩阵的底层依赖一个二维数组。对于无向图来说，如果顶点 i 与顶点 j 之间有边，我们就将 A[i][j]和 A[j][i]标记为 1；
 * 对于有向图来说，如果顶点 i 到顶点 j 之间，有一条箭头从顶点 i 指向顶点 j 的边，那我们就将 A[i][j]标记为 1。
 * 同理，如果有一条箭头从顶点 j 指向顶点 i 的边，我们就将 A[j][i]标记为 1。对于带权图，数组中就存储相应的权重。
 *
 * 邻接表存储方法
 * 一张邻接表的图。乍一看，邻接表是不是有点像散列表？每个顶点对应一条链表，链表中存储的是与这个顶点相连接的其他顶点。
 */
class Graph {
private:
    struct Node {
        int vertex = -1; // 节点名字
        int weight = 1;
        Node *next = nullptr;
    };
    Node **data;
    int size;

public:
    Graph() : Graph(10) {}

    explicit Graph(int size) {
        this->size = size;
        data = new Node *[size];
        // 初始化链表头节点
        for (int i = 0; i < size; i++) {
            data[i] = nullptr;
        }
    }

    virtual ~Graph() = default;

    /**
     * 邻接表存储方法
     * 增加一边, one -> two
     * @param one
     * @param two
     * @return
     */
    bool addEdge(int one, int two) {
        // 越界检查
        if (one > size - 1 || two > size - 1 || one == two) {
            return false;
        }
        // 查找是否已经存在
        Node *pNode = data[one];
        if (pNode == nullptr) {
            data[one] = new Node;
            data[one]->vertex = two;
            return true;
        }

        while (pNode->vertex != two && pNode->next != nullptr) {
            pNode = pNode->next;
        }
        // 不存在则加到末尾
        if (pNode->vertex != two) {
            pNode->next = new Node;
            pNode->next->vertex = two;
        }
        return true;
    }

    /**
     * 邻接表存储方法
     * 删除一边 one -> two
     * @param one
     * @param two
     * @return
     */
    bool delEdge(int one, int two) {
//        cout<< "delEdge " << one << " , " << two << " \n";
        // 越界检查
        if (one > size - 1 || two > size - 1) {
            return false;
        }
        // 查找是否已经存在
        Node *pNode, *preNode;
        preNode = nullptr;
        pNode = data[one];

        // 下一个
        while (pNode != nullptr && pNode->vertex != two) {
            preNode = pNode;
            pNode = pNode->next;
        }
        // 存在则删除
        if (pNode->vertex == two) {
            if (preNode != nullptr) {
                preNode->next = pNode->next;
            } else {
                data[one] = pNode->next;
            }
            delete pNode;
        }
        return true;
    }

    void dump() {
        cout << "dump begin \n";
        for (int i = 0; i < size; i++) {
            cout << "data[" << i << "] -> ";
            Node *pNode = data[i];
            while (pNode != nullptr) {
                cout << pNode->vertex << " -> ";
                pNode = pNode->next;
            }
            cout << "\n";
        }
        cout << "dump end \n\n";
    }

    /**
     * 广度优先搜索
     *
     * 直观地讲，它其实就是一种“地毯式”层层推进的搜索策略，即先查找离起始顶点最近的，然后是次近的，依次往外搜索。
     * @param start
     * @param target
     */
    void breadthFirstSearch(int start, int target) {
        // 记录是否已经访问过了
        int *visited = new int[size];
        // 查询轨迹结论
        int *result = new int[size];
        int resultSize = 0;
        // 初始化 visited
        for (int i = 0; i < size; i++) {
            visited[i] = 0;
        }

        // 队列
        auto *pQueue = new LinkedListQueue<int>();

        // 当前操作节点值
        int temp = start;
//        for(int i = 0 ; i < size; i++){
//
//        }
        function<void(Node *)> tFunc;
        tFunc = [&pQueue, &visited](Node *tempNode) -> void {
            while (tempNode != nullptr) {
                // 如果没有访问过
                if (visited[tempNode->vertex] == 0) {
                    // 入列
                    pQueue->push(tempNode->vertex);
                    // 标记已经访问
                    visited[tempNode->vertex] = 1;
                }
                tempNode = tempNode->next;
            }
        };

        Node *tempNode = data[temp];
        tFunc(tempNode);
        int i = pQueue->pop();
//        result[resultSize++] = i;
        while (i != -1) {
            result[resultSize++] = i;
            if (i != target) {
                // 入列
                tFunc(data[i]);
                i = pQueue->pop();
            } else {
                break;
            }
        }

        // 打印结论
        cout << "RESULT : ";
        for (int in = 0; in < resultSize; in++) {
            cout << result[in] << " ";
        }
        cout << "\n";
    };

    /**
     * 深度优先搜索
     *
     * 假设你站在迷宫的某个岔路口，然后想找到出口。你随意选择一个岔路口来走，走着走着发现走不通的时候，你就回退到上一个岔路口，重新选择一条路继续走，直到最终找到出口。
     * 这种走法就是一种深度优先搜索策略。
     * @param one
     * @param two
     */
    void depthFirstSearch(int one, int two) {
        // 记录是否已经访问过了
        int *visited = new int[size];
        // 查询轨迹结论
        int *result = new int[size];
        int resultSize = 0;
        Node **dataT = data;

        function<void(int, int)> depthFirstSearchReal;

        depthFirstSearchReal = [&visited, &result, &dataT, &depthFirstSearchReal, &resultSize](int oneT, int twoT) {
            Node *pNode = dataT[oneT];
            while (pNode != nullptr) {
                if (pNode->vertex != twoT) {
                    if (visited[oneT] == 0) {
                        visited[oneT] = 1;
                        result[resultSize++] = pNode->vertex;
                        depthFirstSearchReal(dataT[oneT]->vertex, twoT);
                    }
                } else{
                    result[resultSize++] = pNode->vertex;
                    return ;
                }
                pNode = pNode->next;
            }
        };

        depthFirstSearchReal(one, two);
        // 打印结论
        cout << "RESULT : ";
        for (int in = 0; in < resultSize; in++) {
            cout << result[in] << " ";
        }
        cout << "\n";

    };


    static void test() {
        auto *pGraph = new Graph;
        pGraph->addEdge(1, 2);
        pGraph->addEdge(1, 3);
        pGraph->addEdge(1, 4);
        pGraph->addEdge(1, 5);
        pGraph->addEdge(2, 1);
        pGraph->addEdge(2, 2);   // 忽略
        pGraph->addEdge(2, 3);
        pGraph->addEdge(2, 4);
        pGraph->addEdge(2, 5);
        pGraph->dump();
        pGraph->delEdge(1, 2);
        pGraph->delEdge(1, 4);
        pGraph->delEdge(2, 5);
        pGraph->delEdge(2, 1);
        pGraph->dump();


        pGraph->addEdge(1, 2);
        pGraph->addEdge(2, 3);
        pGraph->addEdge(2, 4);
        pGraph->addEdge(3, 5);
        pGraph->addEdge(3, 1);
        pGraph->addEdge(5, 2);
        pGraph->dump();


        pGraph->breadthFirstSearch(1, 4);
        pGraph->depthFirstSearch(1, 4);
    }
};

#endif //DATA_STRUCTURE_GRAPH_HPP
