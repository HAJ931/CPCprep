#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution
{
    public:
    //Function is to check whether two strings are anagram of each other or not.
    bool isAnagram(string a, string b){
        
        // Your code here
        if(a.length() != b.length())
            return false;
        /*map<char, int> hMap;
        for(int i = 0; i < a.size(); ++i){
            hMap[a[i]]++;
        }
        for(int i = 0; i < b.size(); ++i){
            if(hMap.find(b[i]) != hMap.end()){
                hMap[b[i]]--;
                if(hMap[b[i]] == 0)
                    hMap.erase(b[i]);
            }
            else
                return false;
        }
        return true;*/
        vector<int> count1(256, 0), count2(256, 0);
        for(int i = 0; i < a.size(); ++i){
            ++count1[a[i]]; ++count2[b[i]];
        }
        for(int i = 0; i < count1.size(); ++i){
            if(count1[i] != count2[i])
                return false;
        }
        return true;
    }

};

// { Driver Code Starts.

int main() {
    
    int t;

    cin >> t;

    while(t--){
        string c, d;

        cin >> c >> d;
        Solution obj;
        if(obj.isAnagram(c, d)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

}
  // } Driver Code Ends
