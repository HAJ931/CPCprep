//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

vector<long long int> productExceptSelf(vector<long long int>&, int );

// your code will be pasted here

int main()
 {
    int t;  // number of test cases
    cin>>t;
    while(t--)
    {
        int n;  // size of the array
        cin>>n;
        vector<long long int> arr(n),vec(n);
        
        for(int i=0;i<n;i++)    // input the array
        {
            cin>>arr[i];
        }
        
        vec = productExceptSelf(arr,n);   // function call
        
        for(int i=0;i<n;i++)    // print the output
        {
            cout << vec[i] << " ";
        }
        cout<<endl;
    }
	return 0;
}// } Driver Code Ends


//User function template for C++

// nums: given vector
// return the Product vector P that hold product except self at each index
vector<long long int> productExceptSelf(vector<long long int>& nums, int n) {
   
    //code here
    long long int prefix[n], suffix[n];
    long long int prefProd = 1, sufProd = 1;
    vector<long long int> prodArr;
    if (n == 1){
        prodArr.push_back(1);
        return prodArr;
    }
    prefix[0] = 1;
    prefix[1] = 1;
    suffix[n - 1] = 1;
    suffix[n - 2] = 1;
    for(int i = 2; i < n; ++i){
        prefProd *= nums[i - 2];
        prefix[i] = prefProd;
    }
    for(int i = n - 3; i >= 0; --i){
        sufProd *= nums[i + 2];
        suffix[i] = sufProd;
    }
    for(int i = 0; i < n; ++i){
        if (i > 0 && i < n - 1)
            prodArr.push_back(prefix[i] * suffix[i] * nums[i - 1] * nums[i + 1]);
        if (i == 0)
            prodArr.push_back(prefix[i] * suffix[i] * nums[i + 1]);
        if(i == n - 1)
            prodArr.push_back(prefix[i] * suffix[i] * nums[i - 1]);
    }
    return prodArr;
}
