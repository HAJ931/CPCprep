#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    int search(int A[], int l, int h, int key){
    //complete the function here
    int index, left = l, right = h;
        while(left <= right){
            int mid = left + (right - left) / 2;
            if(mid == h || A[mid] > A[mid + 1]){
                index = mid; break;
            }
            else if(A[0] > A[mid])
                right = mid - 1;
            else
                left = mid + 1;
        }
        if(A[index] == key)
            return index;
        if(key < A[index] && A[l] <= key) {
            left = l;
            right = index;
            while(left <= right){
                int mid = left + (right - left) / 2;
                if(A[mid] == key)
                    return mid;
                else if(A[mid] > key)
                    right = mid - 1;
                else
                    left = mid + 1;
            }
        }
        else {
            left = index + 1;
            right = h;
            while(left <= right){
                int mid = left + (right - left) / 2;
                if(A[mid] == key)
                    return mid;
                else if(A[mid] > key)
                    right = mid - 1;
                else
                    left = mid + 1;
            }
        }
        return -1;
        
    }
};

// { Driver Code Starts. 
int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int A[n];
        for(int i = 0; i < n; i++)
            cin >> A[i];
        int key;
        cin >> key;
        Solution ob;
        cout << ob.search(A, 0, n - 1, key) << endl;
    }
return 0;
}  // } Driver Code Ends
