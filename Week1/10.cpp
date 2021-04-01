#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
public:
    vector<int> singleNumber(vector<int> nums) 
    {
        // Code here.
        int exor = 0, exor1 = 0, exor2 = 0;
        for(int i = 0; i < nums.size(); ++i){
            exor ^= nums[i];
        }
        exor = exor & ~(exor - 1);
        for(int i = 0; i < nums.size(); ++i){
            if (exor & nums[i])
                exor1 ^= nums[i];
            else
                exor2 ^= nums[i];
        }
        vector <int> ans;
        if (exor1 <= exor2){
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
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n; 
    	cin >> n;
    	vector<int> v(2 * n + 2);
    	for(int i = 0; i < 2 * n + 2; i++)
    		cin >> v[i];
    	Solution ob;
    	vector<int > ans = ob.singleNumber(v);
    	for(auto i: ans)
    		cout << i << " ";
    	cout << "\n";
    }
	return 0;
}  // } Driver Code Ends
