// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of activities that can
    //be performed by a single person.
    #define pi pair<int, int>
    int activitySelection(vector<int> start, vector<int> end, int n)
    {
        // Your code here
        vector<pi> activities;
        for(int i = 0; i < end.size(); ++i){
            activities.push_back({end[i], start[i]});
        }
        sort(activities.begin(), activities.end());
        int startPtr = 1, endPtr = 0, count = 1;
        while(startPtr < start.size()){
            if(activities[endPtr].first < activities[startPtr].second){
                ++count;
                endPtr = startPtr;
            }
            ++startPtr;
        }
        return count;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    
    //testcases
    cin >> t;
    while(t--)
    {
        //size of array
        int n;
        cin >> n;
        vector<int> start(n), end(n);
        
        //adding elements to arrays start and end
        for(int i=0;i<n;i++)
            cin>>start[i];
        for(int i=0;i<n;i++)
            cin>>end[i];
        Solution ob;
        //function call
        cout << ob.activitySelection(start, end, n) << endl;
    }
    return 0;
}
  // } Driver Code Ends
