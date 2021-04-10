class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int left = 0, firstOdd = 0, currCount = nums[left] % 2 ? 1: 0, totalCount = (k == 1 && nums[left] % 2) ? 1: 0;
        bool flag = 0;
        for(int right = 1; right < nums.size(); ++right){
            if(left < right){
                currCount += nums[right] % 2;
            }
            
            while(currCount > k){
                currCount -= nums[left] % 2;
                ++left;
            }
            
            if(currCount == k){
                firstOdd = left > firstOdd ? left: firstOdd;
                while(nums[firstOdd] % 2 == 0 && firstOdd < nums.size())
                    ++firstOdd;
                totalCount += firstOdd - left + 1;
            }
        }
        return totalCount;
    }
};
