#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    private: 
    bool isValid(vector<int>& count, vector<int>& targetCount){
        for(int i = 0; i < targetCount.size(); ++i){
            if(targetCount[i] > count[i])
                return false;
        }
        return true;
    }
    public:
    //Function to find the smallest window in the string s consisting
    //of all the characters of string p.
    string smallestWindow (string s, string p)
    {
        if(s.length() < p.length())
            return "-1";
        // Your code here
        string res = s + s;
        int left = 0;
        vector<int> targetCount(26, 0), count(26, 0);
        for(auto x: p){
            targetCount[x - 'a']++;
        }
        for(int right = 0; right < s.length(); ++right){
            count[s[right] - 'a']++;
            if(right - left + 1 < p.length())
                continue;
            if(isValid(count, targetCount)){
                while(isValid(count, targetCount) && left <= right){
                    //cout << left << " " << right << "\n";
                    if(right - left + 1 < res.length()){
                        res = "";
                        for(int i = left; i <= right; ++i){
                            res += s[i];
                        }
                        //cout << res << endl;
                    }
                    count[s[left] - 'a']--;
                    ++left;
                }
            }
        }
        if(res == s + s)
            return "-1";
        return res;
    }
};

//{ Driver Code Starts.
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        string pat;
        cin>>pat;
        Solution obj;
        cout<<obj.smallestWindow(s, pat)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends
