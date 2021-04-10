

 // } Driver Code Ends
/*You are required to complete this method*/

// arr[] : the input array containing 0s and 1s
// N : size of the input array

// return the maximum length of the subarray
// with equal 0s and 1s
class Solution{
  public:
    int maxLen(int arr[], int N)
    {
        // Your code here
        unordered_map<int, int> hMap;
        int maxLength = 0;
        int end = -1;
        for(int i = 0; i < N; ++i)
            arr[i] = (arr[i]) ? 1 : -1;
        int sum = 0;
        for(int i = 0; i < N; ++i){
            sum += arr[i];
            if(sum == 0){
                maxLength = i + 1;
                end = i;
            }
            if(hMap.find(sum) != hMap.end()){
                if(maxLength < i - hMap[sum]){
                    maxLength = i - hMap[sum];
                    end = i;
                }
            }
            else
                hMap[sum] = i;
        }
        return maxLength;
    }
};


// { Driver Code Starts.

int main()
{
    // your code goes here
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        Solution obj;
        cout << obj.maxLen(a, n) << endl;
    }
    return 0;
}  // } Driver Code Ends
