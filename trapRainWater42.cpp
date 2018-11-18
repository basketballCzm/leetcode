/*
给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。



上面是由数组 [0,1,0,2,1,0,1,3,2,1,2,1] 表示的高度图，在这种情况下，可以接 6 个单位的雨水（蓝色部分表示雨水）。 感谢 Marcos 贡献此图。

示例:

输入: [0,1,0,2,1,0,1,3,2,1,2,1]
输出: 6
*/

class Solution {
public:
    /**
     * @param heights: a vector of integers
     * @return: a integer
     */
	//左右夹逼，每次选择小的那个指针向中间靠拢
    int trapRainWater(vector<int> &heights) {
        // write your code here
        int ret = 0;
        if(heights.size()==0)
            return ret;
        int lmax = 0, rmax = 0;
        int l = 0, r = heights.size()-1;
        while(l<r)
        {
            lmax = max(lmax,heights[l]);
            rmax = max(rmax,heights[r]);
            if(lmax<rmax)
                ret += lmax-heights[l],l++;
            else
                ret += rmax-heights[r],r--;
        }
        return ret;
    }
};