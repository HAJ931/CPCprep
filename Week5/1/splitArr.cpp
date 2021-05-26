class Solution {
private:
    //This function will be used to split the array into
    //subarrays such that the maximum sum does not exceed
    //the mid value passed
    bool split(vector<int>& nums, int m, int mid){
        int tempSum = 0, numOfArrs = 1;
        for(int i = 0; i < nums.size(); ++i){
            if(tempSum + nums[i] > mid){
                tempSum = nums[i];
                ++numOfArrs;
            }
            else
                tempSum += nums[i];
        }
        //If the number of subarrays is lesser than or equal to the 
        //required number of subarrays m, return true
        if(numOfArrs <= m)
            return true;
        else
            return false;
    }

public:
    //The minimum possible sum would be when a single element is taken in a subarray,
    // and all the other subarrays have elements that have the highest sum <= that element
    // the minimum sum in that case would be the maximum element of the array
    //The maximum possible sum would be when the entire array is taken
    //as a subarray, and the sum in that case would be the sum of the whole array
    int splitArray(vector<int>& nums, int m) {
        //Left will hold max element or the lower bound
        //of the search range
        //Right will hold sum of the array of the upper bound
        //of the search range
        int left = INT_MIN, right = 0;
        for(int i = 0; i < nums.size(); ++i){
            left = nums[i] > left ? nums[i] : left;
            right += nums[i];
        }
        while(left < right){
            int mid = left + (right - left) / 2;
            if(split(nums, m, mid))
                right = mid;
            else
                left = mid + 1;
        }
        return left;
    }
};
