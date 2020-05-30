/*
请定义一个队列并实现函数 max_value 得到队列里的最大值，要求函数max_value、push_back 和 pop_front 的时间复杂度都是O(1)。

若队列为空，pop_front 和 max_value 需要返回 -1

示例 1：

输入: 
["MaxQueue","push_back","push_back","max_value","pop_front","max_value"]
[[],[1],[2],[],[],[]]
输出: [null,null,null,2,1,2]
示例 2：

输入: 
["MaxQueue","pop_front","max_value"]
[[],[],[]]
输出: [null,-1,-1]
 

限制：

1 <= push_back,pop_front,max_value的总操作数 <= 10000
1 <= value <= 10^5


*/

class MaxQueue {
public:
//这里用两个队列来实现，一个队列正常进出，一个队列记录从尾端到该点的最大值，也就是入队元素大于q_max.front()，q_max中的元素就要出队，小于就直接入队。
//出队的时候如果出队元素等于q_max.front。q_max.front中的元素出队。
//我在这题中一直困惑于两个队列的元素要相等。其实两个队列的元素可以不相等。
    deque<int> q;
    deque<int> q_max;
    MaxQueue() {
    }
    
    int max_value() {
        return q_max.empty()?-1:q_max.front();
    }
    
    void push_back(int value) {
        q.push_back(value);
        // 其实这里的最坏也为O(n)
        while(!q_max.empty() && q_max.back() < value){
            q_max.pop_back();
        }
        q_max.push_back(value);
    }
    
    int pop_front() {
        if (q.empty()){
            return -1;
        }
        int res = q.front();
        q.pop_front();
        if (res == q_max.front()){
            q_max.pop_front();
        }
        return res;
    }
};

/**
 * Your MaxQueue object will be instantiated and called as such:
 * MaxQueue* obj = new MaxQueue();
 * int param_1 = obj->max_value();
 * obj->push_back(value);
 * int param_3 = obj->pop_front();
 */