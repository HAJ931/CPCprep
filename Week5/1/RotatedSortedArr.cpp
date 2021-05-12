class Solution {
public:
    int search(vector<int>& nums, int target) {
        int newLim = nums[0], left = 0, right = nums.size() - 1, mid;
        if(nums.size() == 1)
            if(nums[0] == target)
                return 0;
            else return -1;
        while(left <= right){
            mid = left + (right - left) / 2;
            if(mid == nums.size() - 1 || nums[mid] > nums[mid + 1]){
                newLim = mid;
                break;
            }
            else if(nums[0] > nums[mid]){
                right = mid - 1;
            }
            else{
                left = mid + 1;
            }
        }
        if(nums[newLim] == target)
            return newLim;
        else if(nums[newLim] > target && nums[0] <= target){
            left = 0;
            right = newLim;
            while(left <= right){
                mid = left + (right - left) / 2;
                if(nums[mid] == target)
                    return mid;
                else if(nums[mid] < target)
                    left = mid + 1;
                else
                    right = mid - 1;
            }
        }
        else{
            left = newLim + 1;
            right = nums.size() - 1;
            while(left <= right){
                mid = left + (right - left) / 2;
                if(nums[mid] == target)
                    return mid;
                else if(nums[mid] < target)
                    left = mid + 1;
                else
                    right = mid - 1;
            }
        }
        return -1;
    }
};
