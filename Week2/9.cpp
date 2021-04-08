#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
        int closestToZero(int arr[], int n)
        {
            // your code here
            sort(arr, arr + n);
            long long sum, minSum = arr[0] + arr[1];
            int i = 0, j = n - 1;
            while(i < j){
                sum = arr[i] + arr[j];
                if(sum == 0)
                    return sum;
                else if(sum < 0){
                    ++i;
                }
                else
                    --j;
              //Maximum sum closest to zero, condition is handled
                if (abs(sum) <= abs(minSum)){
                    if(abs(minSum) != abs(sum))
                        minSum = sum;
                    else if(minSum < 0)
                        minSum = sum;
                }
            }
            return minSum;
        }
};

// { Driver Code Starts.
int main ()
{
    int t; 
    cin >> t;
    while (t--)
    {
        int n; 
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        Solution ob;
        cout << ob.closestToZero(arr, n) << endl;
    }
}  // } Driver Code Ends
