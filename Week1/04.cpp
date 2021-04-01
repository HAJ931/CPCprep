#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

class Solution{
    public:
    // Function to find the two repeated element
    // arr: input array
    // N: denoting that the size of array is N + 2 and range of elements is [1, N]
    pair<int,int> twoRepeated (int arr[], int N)
    {
        // Your code here
        pair<int, int> ans (-1, -1);
        for(int i = 0; i < N + 2; ++i){
            if(arr[abs(arr[i])] > 0){
                arr[abs(arr[i])] = -(arr[abs(arr[i])]);
            }
          //If element is already negative, then the element stored in arr[i] has appeared for the second time.
            else{
                if(ans.first == -1)
                    ans.first = abs(arr[i]);
                else if(ans.second == -1){
                    ans.second = abs(arr[i]);
                    break;
                }
            }
        }
        return ans;
    }
};

// { Driver Code Starts.

int main()
{
    int t,n;
    cin>>t;
    
    while(t--)
    {
        cin>>n;
        
        int a[n+2];
        
        for(int i=0;i<n+2;i++)
            cin>>a[i];
        
        Solution obj;
        pair<int , int>res;
        res = obj.twoRepeated(a, n);
        cout<<res.first<<" "<<res.second<<endl;
    }
    return 0;
}
  // } Driver Code Ends
