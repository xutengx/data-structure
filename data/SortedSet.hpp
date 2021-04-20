//
// Created by xuteng on 2021/4/19.
//

#ifndef DATA_STRUCTURE_SORTEDSET_HPP
#define DATA_STRUCTURE_SORTEDSET_HPP

#include <random>
#include <ctime>
#include <cassert>
#include "vector"

// 最大深度
#define ZSKIPLIST_MAXLEVEL 32
// 随机层数的系数, 越小出现高层的概率越低, 内存占用越小
#define ZSKIPLIST_P 25

/**
 * 有序集合 (Redis中skiplist实现)
 * https://juejin.cn/post/6844903446475177998
 * 1. zrevrank由数据查询它对应的排名, 这在前面介绍的skiplist中并不支持
 * 2. zscore由数据查询它对应的分数, 这也不是skiplist所支持的
 * 3. zrevrange根据一个排名范围, 查询排名在这个范围内的数据。这在前面介绍的skiplist中也不支持
 * 4. zrevrangebyscore根据分数区间查询数据集合, 是一个skiplist所支持的典型的范围查找(score相当于key)
 */
class SortedSet {
private:
    // zskiplistNode定义了skiplist的节点结构
    struct zskiplistNode {
        // obj字段存放的是节点数据(redis中是 robj *obj ,此处简化为string)
        string *obj = nullptr;
        // score字段是数据对应的分数,即是查找的和排序的key
        double score = 0.0;
        // backward字段是指向链表前一个节点的指针(back指针),节点只有1个前向指针, 所以只有第1层链表是一个双向链表.
        zskiplistNode *backward = nullptr;

        struct zskiplistLevel {
            // 指向各层链表下一个节点的指针(next指针).
            struct zskiplistNode *forward = nullptr;
            // 每个next指针还对应了一个span值, 它表示当前的指针跨越了多少个节点.
            // span用于计算元素排名(rank),这正是前面我们提到的Redis对于skiplist所做的一个扩展
            unsigned int span = 0;
        } ;
        // maxLevel[]是一个柔性数组, 因此它占用的内存不在zskiplistNode结构里面, 而需要插入节点的时候单独为它分配.
        // 也正因为如此, skiplist的每个节点所包含的指针数目才是不固定的, 我们前面分析过的结论——skiplist每个节点包含的指针数目平均为1/(1-p)——才能有意义
        // 柔性数组比较麻烦,在此使用 vector
        vector<zskiplistLevel*> level;

        zskiplistNode(){
            level.push_back(new zskiplistLevel);
        }

    };


    // zskiplist定义了真正的skiplist结构
    struct zskiplist {
        // 头指针header和尾指针tail
        // 头小尾大
        struct zskiplistNode *header, *tail;
        // 链表长度length, 即链表包含的节点总数. 注意,新创建的skiplist包含一个空的头指针,这个头指针不包含在length计数中
        unsigned long length;
        // 所有节点层数的最大值
        int maxLevel;
    };

    zskiplist skipList = *new zskiplist();

    /**
     * 随机生成 每一个节点的层数（maxLevel）
     * @return
     */
    int randomLevel() {
        //生成random_device对象sd做种子
        random_device sd;
        //使用种子初始化linear_congruential_engine对象，为的是使用它来做我们下面随机分布的种子以输出多个随机分布.
        // 注意这里要使用()操作符，因为minst_rand()接受的是一个值（你用srand也是给出这样的一个值）
        minstd_rand random(sd());
        uniform_int_distribution<int> dis1(0, 100);

        int level = 1;
        while ((dis1(random) < ZSKIPLIST_P) && (level <= ZSKIPLIST_MAXLEVEL)) {
            level++;
        }
        return level;
    }

public:
    SortedSet() {
        skipList.length = 0;
        skipList.maxLevel = 1;
        skipList.header = new zskiplistNode;
        skipList.tail = new zskiplistNode;
    }

    ~SortedSet() {
        //  todo
    }

    static void test();

    /**
     * 根据score查找集合中的前一个节点
     * @param obj
     * @return
     */
    zskiplistNode *findBefore(double score) const {
        // 头节点开始寻找
        zskiplistNode *pNode = skipList.header;

        // 从最高层开始寻找
        for (int cLevel = skipList.maxLevel - 1; cLevel >= 0; cLevel--) {

            if(pNode->level.empty()){
                break;
            }
            // 有下一个节点 && 下一个节点小于目标值
            while ((pNode->level)[cLevel]->forward != nullptr && (pNode->level)[cLevel]->forward->score < score) {
                // 继续寻找 (当上面的 while 条件不成立时, 外层 for 循环中 cLevel 会 --, 即level降级寻找)
                pNode = (pNode->level)[cLevel]->forward;
            }
        }
        return pNode;
    }

    /**
     * 根据score查找集合中的节点
     * @param obj
     * @return
     */
    zskiplistNode *find(double score) const {
        // 根据score查找集合中的前一个节点
        zskiplistNode *pNode = findBefore(score);
        // pNode 即为小于目标值的节点, 验证下一个节点是否即为目标值
        if ((pNode->level)[0]->forward != nullptr && (pNode->level)[0]->forward->score == score) {
            return (pNode->level)[0]->forward;
        }
        return nullptr;
    }

    /**
     * 根据成员查找集合中的节点 (不是skiplist所支持的)
     * @param obj
     * @return
     */
    zskiplistNode *find(string *obj) const {
        // todo 通过obj hash找到对应的score, 在调用 zskiplistNode *find(double score) const
        double score = 0.0;
        return find(score);
    }

    /**
     * 将一个值加入集合
     * @param score
     * @param obj
     * @return
     */
    int zadd(double score, string *obj) {
        // todo 通过obj hash存储对应的score, 方便后续查找
        // todo 先忽略span
        auto *pNode = new zskiplistNode;
        pNode->score = score;
        pNode->obj = obj;

        // 先查找对应 score 前一个节点
        zskiplistNode *pNodeBefore = findBefore(score);

        // 设置后一节点的 back指针
        if(pNodeBefore->level[0]->forward != nullptr){
            pNodeBefore->level[0]->forward->backward = pNode;
        }

        // 赋值level
        int level = randomLevel();
        for (int i = 0 ; i < level; i++) {

            // 设置新节点的 next指针
            pNode->level[i]->forward = pNodeBefore->level[0]->forward;
            // 设置前一节点的 next指针
            pNodeBefore->level[i]->forward = pNode;
        }
        // 设置新节点的 back指针
        pNode->backward = pNodeBefore;

        // 记录
        if(level > skipList.maxLevel){
            skipList.maxLevel = level;
        }
        return 1;
    }

    /**
     * 返回集合数据总数
     * @return
     */
//    unsigned long zcard() {
//
//    }

    /**
     * 分数值在 min 和 max 之间的成员的数量
     * @param min
     * @param max
     * @return
     */
//    unsigned long zcount(double min, double max) {
//
//    }

    /**
     * 返回有序集中指定成员的排名
     * @param obj
     * @return
     */
//    int zrank(string *obj) {
//
//    }

    /**
     * 命令用于移除有序集中的一个，不存在的成员将被忽略
     * @param obj
     * @return
     */
//    int zrem(string *obj) {
//
//    }

    /**
     * 对有序集合中指定成员的分数加上增量 increment
     * @param increment
     * @param obj
     * @return 自增后的分数
     */
//    double zincrby(double increment, string *obj) {
//
//    }

    /**
     * 根据分数区间查询数据集合
     * @param min
     * @param max
     * @return
     */
//    string **zrevrangebyscore(double min, double max) {
//
//    }

    /**
     * 由数据查询它对应的分数, 不是skiplist所支持的
     * @param obj
     * @return
     */
//    double zscore(string *obj) {
//
//    }

    /**
     * 由数据查询它对应的排名, skiplist中并不支持
     * @param obj
     * @return
     */
//    int zrevrank(string *obj) {
//
//    }

    /**
     * 根据一个排名范围，查询排名在这个范围内的数据
     * @param low
     * @param high
     * @return
     */
//    string **zrevrange(int low, int high) {
//
//    }
};

void SortedSet::test() {
    auto *pSet = new SortedSet;
    string str1 = "str1";
    string str2 = "str2";
    string str3 = "str3";
    string str4 = "str4";

    pSet->zadd(1, &str1);
    pSet->zadd(2, &str2);
    pSet->zadd(3, &str3);
    pSet->zadd(4, &str4);

    string *pString = pSet->find(2)->obj;
    assert(pString == &str2);
    
}

#endif //DATA_STRUCTURE_SORTEDSET_HPP
