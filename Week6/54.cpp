#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
private:
    void sortedArrayToBSTUtil(int left, int right, vector<int>& nums, vector<int>& res){
        if(right < left){
            return;
        }
        int mid = left + (right - left) / 2;
        res.push_back(nums[mid]);
        sortedArrayToBSTUtil(left, mid - 1, nums, res);
        sortedArrayToBSTUtil(mid + 1, right, nums, res);
    }
public:
    vector<int> sortedArrayToBST(vector<int>& nums) {
        // Code here
        vector<int> res;
        sortedArrayToBSTUtil(0, nums.size() - 1, nums, res);
        return res;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)cin >> nums[i];
		Solution obj;
		vector<int>ans = obj.sortedArrayToBST(nums);
		for(auto i: ans)
			cout << i <<" ";
		cout << "\n";
	}
	return 0;
}  // } Driver Code Ends
