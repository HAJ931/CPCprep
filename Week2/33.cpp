class Solution {
    private:
    int atMostK(vector<int>& nums, int k){
        if(!k || !nums.size())
            return 0;
        int left = 0, right = 0, res = 0;
        unordered_map<int, int> hMap;
        while(left < nums.size() && right < nums.size()){
            while(hMap.size() == k){
                hMap[nums[left]]--;
                if(hMap[nums[left]] == 0)
                    hMap.erase(nums[left]);
                ++left;
            }
            
            while(right < nums.size()){
                if(hMap.count(nums[right]))
                    hMap[nums[right]]++;
                else if(hMap.size() == k){
                    break;
                }
                else {
                    hMap[nums[right]]++;
                }
                res += right - left + 1;
                //cout << right - left + 1 << endl;
                //cout << left << " " << right << " " << res << endl;
                ++right;
            }
        }
        return res;
    }
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMostK(nums, k) - atMostK(nums, k - 1);
    }
};
