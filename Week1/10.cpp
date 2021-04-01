//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++
class Solution{
    public:
    vector<int> twoOddNum(int Arr[], int N)  
    {
        // code here
        int exor = 0, exor1 = 0, exor2 = 0;
        vector <int> ans;
        for(int i = 0; i < N; ++i){
            exor ^= Arr[i];
        }
        exor = exor & ~(exor - 1); //Finding the rightmost set bit
      //This indicates the two numbers have different values
        for(int i = 0; i < N; ++i){
            if (Arr[i] & exor) //Segregate the numbers into two arrays based on the value of the set bit position
                exor1 ^= Arr[i]; 
            else
                exor2 ^= Arr[i];
        }
        if(exor1 >= exor2){
            ans.push_back(exor1);
            ans.push_back(exor2);
        }
        else{
            ans.push_back(exor2);
            ans.push_back(exor1);
        }
        return ans;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        int Arr[N];
        for(int i = 0;i < N;i++)
        cin>>Arr[i];
        Solution ob;
        vector<int>ans=ob.twoOddNum(Arr,N);
        for(int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends
