class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        if(arr.size() == 1)
            return 0;
        int left = 0, right = arr.size() - 1, mid;
        while(left < right){
            mid = left + (right - left) / 2;
            if(arr[mid] > arr[mid + 1])
                right = mid;
            else
                left = mid + 1;
        }
        return left;
    }
};
