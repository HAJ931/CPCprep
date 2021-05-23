class Solution {
public:
    
    double pow(double a, long long n){
        if(n == 0)
            return 1;
        double x = pow(x, n / 2);
        x *= x;
        if(n % 2 == 1)
            x *= a;
        return x;
    }
    
    double myPow(double x, int n) {
        long long int exp = n;
        if(exp >= 0)
            return pow(x, exp);
        return 1 / pow(x, -(exp));
    }
};
