#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

class Solution
{
    int t[1000][1000];
    int getMax(int a, int b){
        return a > b ? a: b;
    }
    int knapSackUtil(int wt[], int val[], int n, int W){
        if(n == 0 || W == 0)
            return 0;
        if(t[n][W] != -1)
            return t[n][W];
        if(wt[n - 1] <= W)
            return t[n][W] = getMax(val[n - 1] + knapSackUtil(wt, val, n - 1, W - wt[n - 1]), 
                knapSackUtil(wt, val, n - 1, W));
        else
            return t[n][W] = knapSackUtil(wt, val, n - 1, W);
    }
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       memset(t, -1, sizeof(t));
       return knapSackUtil(wt, val, n, W);
       
    }
};

// { Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}  // } Driver Code Ends
