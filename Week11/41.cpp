class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n == 0)
            return false;
        while(n){
            if(n % 2 != 0)
            {
                if(n == 1)
                    return true;
                else
                    break;
            }
            n /= 2;
        }
        return false;
    }
};
