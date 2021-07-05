#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    public:
    //Function to reverse words in a given string.
    string reverseWords(string S) 
    { 
        // code here 
        stack<string> s;
        for(int i = 0; i < S.size();){
            while(i < S.size() && S[i] == '.')
                ++i;
            string curr = "";
            curr += S[i];
            //cout << i << ": " << curr << "\n"; 
            ++i;
            while(i < S.size() && S[i] != '.'){
                curr += S[i];
                ++i;
            }
            s.push(curr);
            ++i;
        }
        string res = "";
        while(!s.empty()){
            res += s.top();
            s.pop();
            if(!s.empty())
                res += '.';
        }
        return res;
    } 
};

// { Driver Code Starts.
int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        string s;
        cin >> s;
        Solution obj;
        cout<<obj.reverseWords(s)<<endl;
    }
}  // } Driver Code Ends
