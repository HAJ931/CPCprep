#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    private:
        void findPermUtil(string s, vector<string>& res, int left, int right){
            if(left == right){
                res.push_back(s);
                return;
            }
            for(int i = left; i <= right; ++i){
              //Swap the leftmost element with the elements including itself and the ones to its right, one by one
                swap(s[left], s[i]);
              //Find the permutations of the right substring, keeping the left substring (indices 0 to left) constant
                findPermUtil(s, res, left + 1, right);
              //Backtrack to find other permutations
                swap(s[left], s[i]);
            }
            
        }
	public:
		vector<string>find_permutation(string S)
		{
		    // Code here there
		    vector<string> res;
		    findPermUtil(S, res, 0, S.length() - 1);
		    sort(res.begin(), res.end());
		    return res;
		}
};



// { Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}
  // } Driver Code Ends
