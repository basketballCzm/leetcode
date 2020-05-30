int find(vector<int> v, int target){
    sort(v.begin(), v.end())
    int left = 0;
    int right = v.size()-1;
    while(left <= right){
        int mid = left + (right-left)>>1;
        if(v[mid] < target){
            left = mid+1;
        }else if (v[mid] > target){
            right = mid-1;
        }else{
            return left;
        }
    }

    return -1;
}