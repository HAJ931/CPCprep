class Solution {
public:
    int fib(int n) {
        if(n <= 0)
            return 0;
        if(n == 1 || n == 2)
            return 1;
        vector<int> res(n + 1, 0);
        for(int i = 1; i < res.size(); ++i){
            if(i == 1 || i == 2)
                res[i] = 1;
            else
                res[i] = res[i - 2] + res[i - 1];
        }
        return res[n];
    }
};
