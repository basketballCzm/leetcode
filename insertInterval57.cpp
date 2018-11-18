/*
给出一个无重叠的 ，按照区间起始端点排序的区间列表。

在列表中插入一个新的区间，你需要确保列表中的区间仍然有序且不重叠（如果有必要的话，可以合并区间）。

示例 1:

输入: intervals = [[1,3],[6,9]], newInterval = [2,5]
输出: [[1,5],[6,9]]
示例 2:

输入: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
输出: [[1,2],[3,10],[12,16]]
解释: 这是因为新的区间 [4,8] 与 [3,5],[6,7],[8,10] 重叠。
*/


/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
/*
思路:首先将新的区间按顺序插入原来的intervals中，然后冉钊前面的方法，创建res，依次比较intervals中的元素和res中的最后一个元素的区间值，如果重复则合并，如果不重复直接插入res中。
注意事项:
intervals中的区间值的starts值必须是从小到大依次排列的
*/
class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        int size = intervals.size();
        int index = 0;
        vector<Interval> res;
        for(int i = 0; i < size; i++, index++){
            if(intervals[i].start >= newInterval.start){
                break;
            }
        }

        intervals.insert(intervals.begin()+index,newInterval);

        res.insert(res.begin(), intervals[0]);

        for(int i = 1; i < size+1; i++){
            if(res.back().end >= intervals[i].start){
                res.back().end = res.back().end>intervals[i].end ? res.back().end : intervals[i].end;
            }else{
                res.push_back(intervals[i]);
            }
        }

        return res;
    }
};