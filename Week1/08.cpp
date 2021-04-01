int Solution::repeatedNumber(const vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int count1 = 0, count2 = 0, el1 = A[0], el2 = A[1];
  //The first loop checks to see which two elements occur the most number of times
    for(int i = 0; i < A.size(); ++i){
        if(A[i] == el1)
            ++count1;
        else if(A[i] == el2)
            ++count2;
        else if(count1 == 0){
            el1 = A[i];
            ++count1;
        }
        else if(count2 == 0){
            el2 = A[i];
            ++count2;
        }
        else{
            --count1;
            --count2;
        }
        
    }
  //The next loop will count the actual number of occurrences of the two elements
    int freq1 = 0, freq2 = 0;
    for(int i = 0; i < A.size(); ++i){
        if(el1 == A[i])
            ++freq1;
        if(el2 == A[i])
            ++freq2;
    }
    if (freq1 > (A.size() / 3)) 
        return el1;
    if (freq2 > (A.size() / 3)) 
        return el2;
    return -1;
}
