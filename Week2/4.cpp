vector<vector<int> > Solution::threeSum(vector<int> &A) {
    sort (A.begin(), A.end());
    int j, k, n = A.size();
    vector<vector<int>> ans;
    for(int i = 0; i < n - 2; ++i){
        if(i > 0 && A[i] == A[i - 1])
            continue;
        j = i + 1;
        k = n - 1;
        while(j < k){
            long long sum = 0LL + A[i] + A[j] + A[k];
            if(sum == 0){
                ans.push_back({A[i], A[j], A[k]});
                while(j < n - 1 && A[j] == A[j + 1])
                    ++j;
                while(k > 0 && A[k] == A[k - 1])
                    --k;
                ++j, --k;
            }
            else if(sum < 0)
                ++j;
            else
                --k;
        }
    }
    return ans;
}
