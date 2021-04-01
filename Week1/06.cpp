int Solution::firstMissingPositive(vector<int> &A) {
    for(int i = 0; i < A.size(); ++i){
        if(A[i] > 0 && A[i] <= A.size())
        {
            int pos = A[i] - 1;
            if(A[i] != A[pos]){
                swap(A[i], A[pos]);
                --i;
            }
        }
    }
    for(int i = 0; i < A.size(); ++i){
        if(A[i] != i + 1)
            return i + 1;
    }
    return A.size() + 1;
    
}
