class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int left = 0, count = nums[0] < k ? 1: 0;
        long long currProd = nums[0];
        for(int right = 1; right < nums.size(); ++right){
            currProd *= nums[right];
            while(currProd >= k && left < right){
                currProd /= nums[left];
                ++left;
            }
            if(currProd < k)
                count += right - left + 1;
        }
        return count;
    }
};
