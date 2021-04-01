class Solution {
public:
    bool isPalindrome(int x) {
        int temp, currDigit, reverse = 0;
        if (x < 0)
            return false;
        temp = x;
        while (temp != 0){
            currDigit = temp % 10;
            if (reverse > INT_MAX / 10 || (reverse == INT_MAX / 10 && currDigit > 7)) 
                return 0;
            if (reverse < INT_MIN / 10 || (reverse == INT_MIN / 10 && currDigit < -8)) 
                return 0;
            reverse = reverse * 10 + currDigit;
            temp /= 10;
        }
        if(x == reverse)
            return true;
        return false;
    }
};
