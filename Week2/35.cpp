// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
    private:
        bool isPrime(int N){
            if(N < 2)
                return false;
            for(int i = 2; i <= sqrt(N); ++i){
                if(N % i == 0)
                    return false;
            }
            return true;
        }
        bool isPalindrome(int N) {
            int rev = 0;
            int temp = N;
            while(temp){
                rev *= 10;
                rev += temp % 10;
                temp /= 10;
            }
            return rev == N;
        }
        bool isAllNines(int N) {
            while(N){
                if(N % 10 != 9)
                    return false;
                N /= 10;
            }
            //cout << "Returning true." << "\n";
            return true;
        }
        int nextPalindrome(int N){
            string str = to_string(N);
            int n = str.length();
            vector<int> num(n);
            for(int i = 0; i < n; ++i){
                num[i] = str[i] - '0';
                //cout << num[i] << " ";
            }
            // Case 1: All 9's
            if(isAllNines(N)){
                return N + 2; 
            }
            int mid = n / 2;
            int i, j;
            if(n % 2)
                j = mid + 1;
            else
                j = mid;
            i = mid - 1;
            bool incr = false;
            while(i >= 0 && num[i] == num[j]){
                --i;
                ++j;
            }
            incr = i < 0 || num[i] < num[j];
            while (i >= 0) {
                num[j++] = num[i--];
            }
            if(incr) {
                int carry = 1;
                i = mid - 1;
                if(n % 2){
                    j = mid + 1;
                    num[mid] += carry;
                    carry = num[mid] / 10;
                    num[mid] %= 10;
                }
                else
                    j = mid;
                while(i >= 0){
                    num[i] += carry;
                    carry = num[i] / 10;
                    num[i] %= 10;
                    num[j++] = num[i--];
                }
                if(carry)
                    num.insert(num.begin(), carry);
            }
            int res = 0;
            for(auto x: num){
                res *= 10;
                res += x;
            }
            return res;
        }
	public:
		int PrimePalindrome(int N){
		    // Code here
		    //cout << nextPalindrome(81881) << " ";
		    if(isPrime(N) && isPalindrome(N))
		            return N;
	       return PrimePalindrome(nextPalindrome(N));
		}

};


// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int N;
		cin >> N;
		Solution obj;
		int ans = obj.PrimePalindrome(N);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends
