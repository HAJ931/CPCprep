
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
private:
    bool isSubset(int arr[], vector<vector<bool>>& vis, vector<vector<bool>>& mem, int n, int sum){
        if(n == 0 && sum != 0)
            return false;
        if(sum == 0)
            return true;
        bool res;
        if(vis[n][sum])
            res = mem[n][sum];
        else if(arr[n - 1] <= sum)
          //Try both including the last element of the current subarray as well as excluding it to reach the answer
            res = (isSubset(arr, vis, mem, n - 1, sum) || isSubset(arr, vis, mem,  n - 1, sum - arr[n - 1]));
        else res = false;
      //Store the computed values for faster computing in the future
        vis[n][sum] = true;
        mem[n][sum] = res;
        return res;
    }
public:
    int equalPartition(int N, int arr[])
    {
        // code here
        int sum = 0;
        for(int i = 0; i < N; ++i){
            sum += arr[i];
        }
      //If the sum is odd, the array obviously cannot be partitioned into two with equal sums, return false
        if(sum % 2 != 0)
            return 0;
        vector<vector<bool>> vis(N + 1, vector<bool>(sum, false));
        vector<vector<bool>> mem(N + 1, vector<bool>(sum, false));
      //Else, check if there exists a sub array with sum equal to half of the total sum (self - explanatory)
        if(isSubset(arr, vis, mem, N, sum / 2))
            return 1;
        return 0;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}  // } Driver Code Ends
