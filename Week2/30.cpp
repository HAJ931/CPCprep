class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int sum = nums[0], max = nums[0];
        for(int i = 1; i < nums.size(); ++i){
            if(nums[i] <= nums[i - 1])
                sum = 0;
            sum += nums[i];
            if(max < sum)
                max = sum;
        }
        return max;
    }
};
