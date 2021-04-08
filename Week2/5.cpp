int Solution::threeSumClosest(vector<int> &A, int B) {
    sort (A.begin(), A.end());
    int j, k, n = A.size();
    if(n < 3)
        return -1;
    int diff = INT_MAX;
    long long sum, minSum;
    for(int i = 0; i < n - 2; ++i){
        if(i > 0 && A[i] == A[i - 1])
            continue;
        j = i + 1;
        k = n - 1;
        while (j < k) {
            sum = A[i] + A[j] + A[k];
            if (abs(B - sum) < abs(B - minSum))
                minSum = sum;
            if (sum > B)
                --k;
            else
                ++j;
        }
    }
    return minSum;
}
