# leetcode
leetcode题目

## 算法总结
1. 对于DFS确定基本的写法，尽量在第最外层什么也不做，连visited变量的改变都要放在递归的函数中去做，这样可以防止相同的代码写两遍。网站上的oj如果是最明显的递归算法一般要用非递归算法才能达到oj指定的时间复杂度。search_word79.cpp。
2. 链表基本操作要进行删除元素，那么在循环的过程中尽量使用前驱进行循环。提前校验head,head->next。new一个空头部。头插法pcur是空头后一位。
3. 对于查找查找类的题目首先考虑二分查找，但是二分查找的一半情况下的前提是该序列是一个有序的序列。但是有不是有序序列而使用二分查找的情况，如这道题：162 寻找峰值。
4. 对于二分查找插入，带等号的就不用加1。计算右侧小于当前元素的个数if(t[mid] >= nums[i]) right = mid;最后的插入位置必须要使用right来标记，不然[-1, -1]会有问题。（rotateArray比较也要用right）

## 笔试注意事项 
1. 输入输出需要注意  while(cin >> a) cin >> a，输入成功返回一个对象，输入失败返回false。scanf("%d", &a) 输入成功返回输入个数，输入失败返回0。

Item                     | Value
-----                    | -----
1.两数之和                |
2.两数相加                |
3.无重复字符的最长子串     |
4.两个排序数组的中位数     |
5.最长回文子串            |
6.Z字形变换               |
7.反转整数                |
8.字符串转整数 (atoi)     |
9.回文数                 |
10.正则表达式匹配         |
11.盛最多水的容器          |
12.整数转罗马数字          |
13.罗马数字转整数          |
14.最长公共前缀            |
15.三数之和               |
16.最接近的三数之和        |
17.电话号码的字母组合       |
18.删除链表的倒数第N个节点  |
19.有效的括号              |
20.四数之和                |
