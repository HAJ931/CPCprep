vector<int> Solution::repeatedNumber(const vector<int> &A) {
    long long sum = 0; //A - B
    long long squareSum = 0;
    long long temp;
    vector<int> arr;
    for(int i = 0; i < A.size(); ++i){
        temp = A[i];
        sum += temp;
        sum -= (i + 1); //Step-by-step subtraction of numbers to avoid overflow
        squareSum += (temp * temp);
        squareSum -= ((long long) (i + 1) * (long long) (i + 1)); 
    }
    squareSum /= sum; //A+B
    arr.push_back((int) ((sum + squareSum) / 2));
    arr.push_back((int) ((squareSum - sum) / 2));
    return arr;
}
