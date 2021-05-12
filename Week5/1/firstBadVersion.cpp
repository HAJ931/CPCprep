// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        if(n == 1)
            return isBadVersion(1) ? 1: 0;
        int left = 1, right = n, mid;
        while(left < right){
            mid = left + (right - left) / 2;
            if(isBadVersion(mid) && !isBadVersion(mid + 1))
                return mid + 1;
            else if(!isBadVersion(mid))
                left = mid + 1;
            else
                right = mid;
        }
        return left;
    }
};
