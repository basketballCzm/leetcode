/*
运用你所掌握的数据结构，设计和实现一个  LRU (最近最少使用) 缓存机制。它应该支持以下操作： 获取数据 get 和 写入数据 put 。

获取数据 get(key) - 如果密钥 (key) 存在于缓存中，则获取密钥的值（总是正数），否则返回 -1。
写入数据 put(key, value) - 如果密钥不存在，则写入其数据值。当缓存容量达到上限时，它应该在写入新数据之前删除最近最少使用的数据值，从而为新的数据值留出空间。

进阶:

你是否可以在 O(1) 时间复杂度内完成这两种操作？

示例:

思路：
使用两个栈空间来解题会造成超出时间限制。

然后一般的LRUCache采取的策略为hashmap+双向链表，由于c++STL中的list就是双向链表，则可以直接用。
这一遍写错了很多次，原因主要有一下：
1. 对STL的用法又忘记了。l.splice(position,list,iterator(fast,last));将链表中的指定元素插入到指定位置
2. 对具体算法还是存在模糊，后面要多写这个问题。
*/

struct Point{
    int x;
    int y;
};
class LRUCache {
public:
    stack<Point> stk1;
    stack<Point> stk2;
    int cap;
    int cnt;
    LRUCache(int capacity) {
        cap = capacity;
        cnt = 0;
    }
    
    int get(int key) {
        if(stk1.empty()){
            return -1;
        }
        
        while(!stk1.empty()){
            Point p = stk1.top();
            stk1.pop();
            if(p.x == key){
                while(!stk2.empty()){
                    stk1.push(stk2.top());
                    stk2.pop();
                }
                stk1.push(p);
                return p.y;
            }
            stk2.push(p);
        }
        while(!stk2.empty()){
            stk1.push(stk2.top());
            stk2.pop();
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(cnt == cap){
            while(!stk1.empty()){
                Point P = stk1.top();
                stk1.pop();
                if(P.x != key){
                    stk2.push(P);
                }else{
                    stk2.push(P);
                    break;
                }
            }
            stk2.pop();
        }else{
            int flag = 0;
            while(!stk1.empty()){
                Point P = stk1.top();
                stk1.pop();
                if(P.x != key){
                    stk2.push(P);
                }else{
                    flag = 1;
                    break;
                }
            }
            if(0 == flag){
               cnt++; 
            }
        }
        while(!stk2.empty()){
            stk1.push(stk2.top());
            stk2.pop();
        }
        stk1.push(Point{key, value});
    }
};

class LRUCache {
public:
    int cap;
    list<pair<int,int>> l;
    unordered_map<int, list<pair<int,int>>::iterator> m;
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        auto it = m.find(key);
        // unordered_map没有查找到元素
        if(it == m.end()){
            return -1;
        }
        //STL不熟悉
        l.splice(l.begin(), l, it->second);
        return it->second->second;
    }
    
    void put(int key, int value) {
        auto it = m.find(key);
        if(it != m.end()){
            // x->second->second = value;
            l.erase(it->second);
            // return; 这里写return?
        }
        l.push_front(make_pair(key, value));
        m[key] = l.begin();
        // 
        if(m.size() > cap){
            int k = l.rbegin()->first;
            l.pop_back();
            m.erase(k);
        }
        
    }
};
