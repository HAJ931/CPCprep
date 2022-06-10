class Solution {
public:
    int hammingDistance(int x, int y) {
        int exor = x ^ y;
        int count = 0;
        while(exor){
            ++count;
            exor = exor & (exor - 1);
        }
        return count;
    }
};
