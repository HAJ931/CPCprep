class Solution {
public:
    int mySqrt(int x) {
        if (x == 1 || x == 0)
            return x;
        int left = 1;
        int right = x - 1;
        int mid, ans = 0;
        while(left <= right){
            mid = left + (right - left) / 2;
          //Divide rather than multiplying mid by itself to avoid overflow
            if(mid == x / mid)
                return mid;
            else if(mid > x / mid)
                right = mid - 1;
            else{
                left = mid + 1;
                ans = mid;
            }
        }
        return ans;
    }
};
