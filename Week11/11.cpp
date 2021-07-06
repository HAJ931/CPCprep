int Solution::atoi(const string A) {
    int i = 0;
    long long res = 0;
    bool flag = true, encountered = false, signEncountered = false;
    while(i < A.length()){
        if(!isdigit(A[i])){
            if(encountered){
                if(flag)
                    return res;
                else
                    return -1 * res;
            }
            else if(A[i] == ' ' || A[i] == '+' || A[i] == '-'){
                if(A[i] == ' ' && signEncountered)
                    return 0;
                if(A[i] == '-'){
                    signEncountered = true;
                    flag = false;
                }
                if(A[i] == '+'){
                    signEncountered = true;
                }
                ++i;
                continue;
            }
            else
                return 0;
        }
        if(flag){
            if(res > INT_MAX / 10)
                return INT_MAX;
            if(res == INT_MAX / 10)
                if(A[i] - '0' > 7)
                    return INT_MAX;
        }
        else{
            if(res > INT_MAX / 10)
                return INT_MIN;
            if(res == INT_MAX / 10)
                if(A[i] - '0' > 7)
                    return INT_MIN;
        }
        encountered = true;
        res *= 10;
        res += A[i] - '0';
        ++i;
    }
    if(flag)
        return res;
    return -res;
}
