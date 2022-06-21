class Solution {
private: 
    int gcd(int a, int b){
        if(b == 0)
            return a;
        if(b == 1)
            return 1;
        return gcd(b, a % b);
    }
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k %= n;
        if(!k)
            return;
        int lim = gcd(n, k);
        for(int i = 0; i < lim; ++i){
            int j = i;
            int pre = nums[i], curr = nums[(i + k) % n];
            nums[(j + k) % n] = pre;
            pre = curr;
            j = (j + k) % n;
            while(j != i){
                curr = nums[(j + k) % n];
                nums[(j + k) % n] = pre;
                pre = curr;
                j = (j + k) % n;
            }
        }
    }
};
