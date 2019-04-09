/*
题目描述
输入n个整数，找出其中最小的K个数。例如输入4,5,1,6,2,7,3,8这8个数字，则最小的4个数字是1,2,3,4,。
*/

/**基于堆排序算法，构建最大堆。时间复杂度为O(nlogk)
*如果用快速排序，时间复杂度为O(nlogn)；
*如果用冒泡排序，时间复杂度为O(n*k)*/
class Solution {
  public:
    //大根堆  比根节点小的数进行替换根节点
    //与堆排序全部元素建立堆不一样，这里可以只用四个元素建立大根堆，然后每次来的元素比根节点小的进行替换
    //这里一直显示报错是因为在参数传递的时候没有加引用。
    void Heapify(vector<int>& input, int mid, int size) {
        int left_child = 2 * mid + 1;
        int right_child = 2 * mid + 2;
        int max = mid;
        if (left_child < size && input[left_child] > input[max]) {
            max = left_child;
        }

        if (right_child < size && input[right_child] > input[max]) {
            max = right_child;
        }

        if (max != mid) {
            input[max] = input[max] + input[mid];
            input[mid] = input[max] - input[mid];
            input[max] = input[max] - input[mid];
            Heapify(input, max, size);
        }
    }

    int buildHeap(vector<int>& input, int k) {
        int heap_size = k;
        for (int i = heap_size / 2 - 1; i >= 0; i--) {
            Heapify(input, i, k);
        }
        return heap_size;
    }
    vector<int> GetLeastNumbers_Solution(vector<int>& input, int k) {
        if (input.size() < k) {
            return vector<int> {};
        }
        int size = buildHeap(input, k);
        for (int i = k; i < input.size(); i++) {
            if (input[0] > input[i]) {
                input[0] = input[0] + input[i];
                input[i] = input[0] - input[i];
                input[0] = input[0] - input[i];
                Heapify(input, 0, k);
            }
        }

        return vector<int>(input.begin(), input.begin() + k);
    }
};