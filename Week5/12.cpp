class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.size() == 1)
            if(nums[0] == target)
                return{0, 0};
            else
                return {-1, -1};
        int left = 0, right = nums.size() - 1;
        //Finding the leftmost integer that matches the target
        while(left <= right){
            int mid = left + (right - left) / 2;
            if(nums[mid] >= target)
                right = mid - 1;
            else
                left = mid + 1;
        }
        //Lowerbound is actually right + 1, but assign as right for easier post-processing
        int lowerBound = right;
        //Finding the rightmost integer that matches the target
        left = 0, right = nums.size() - 1;
        while(left <= right){
            int mid = left + (right - left) / 2;
            if(nums[mid] <= target)
                    left = mid + 1;
            else
                right = mid - 1;
        }
        //Upperbound is actually left - 1, but assign as left for easier post-processing
        int upperBound = left;
        //Post-processing: If element is not present, upperBound = lowerBound + 1
        if(upperBound - lowerBound == 1)
            return {-1, -1};
        return {lowerBound + 1, upperBound - 1};
        
    }
};
