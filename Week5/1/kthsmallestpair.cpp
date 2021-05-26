class Solution {
private:    
    bool condSat(vector<int>& nums, int k, int mid){
        int left = 0, count = 0;
        //Finding the number of pairs with difference less than or equal to mid
        for(int right = 0; right < nums.size(); ++right){
            //if the difference of the first and last elements is greater than mid, then
            //we have to increase left index, since the array is sorted
            while(nums[right] - nums[left] > mid) ++left;
            //Number of elements with difference less than or equal to mid
            //will be the elements currently in the sliding window
            count += right - left;
        }
        if(count >= k) return true;
        return false;
    }
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int left = 0, right = nums[nums.size() - 1] - nums[0];
        while(left < right){
            int mid = left + (right - left) / 2;
            if(condSat(nums, k, mid))
                right = mid;
            else
                left = mid + 1;
        }
        return left;
    }
};
