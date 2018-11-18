/*
给出一个区间的集合，请合并所有重叠的区间。

示例 1:

输入: [[1,3],[2,6],[8,10],[15,18]]
输出: [[1,6],[8,10],[15,18]]
解释: 区间 [1,3] 和 [2,6] 重叠, 将它们合并为 [1,6].
示例 2:

输入: [[1,4],[4,5]]
输出: [[1,5]]
解释: 区间 [1,4] 和 [4,5] 可被视为重叠区间。
*/

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };

	vector<int> vec0;//六种初始化方式；
	vector<int> vec5(othervec);
	vector<int> vector(other.begin(), other.end());
	vector<int> vec1{ 1, 2, 3, 4, 5 };
	vector<int> vec2(10, 1);
	vector<int> vec3 = { 1, 2, 3, 4, 5, 6 };
 */
/*
解题思路：首先将区间按照起始区间的大小按照先后顺序进行排序，首先将第一个区间放入结果区间，然后依次遍历区间，比较结果区间最后一个区间的尾部和当前遍历区间的首部，分为两种情况，当end<start,直接插入，当end>=start,合并两个区间。
*/
class Solution {
public:
	bool myfunction(Interval v1, Interval v2){
		return v1.start < v2.start;
	}

    vector<Interval> merge(vector<Interval>& intervals) {
    	int size = intervals.size();
    	if(0 == size || 1 == size){
    		return intervals;
    	}
    	std::sort(intervals.begin(), intervals.end(), [](Interval &a, Interval &b){return a.start < b.start;});
    	vector<Interval> res{intervals[0]};
    	for(int i = 1; i < size; i++){
    		if(res.back().end < intervals[i].start){
    			res.push_back(intervals[i]);
    		}
    		else{
    			res.back().end = max(res.back().end, intervals[i].end);
    		}
    	}

    	return res;
    }
};