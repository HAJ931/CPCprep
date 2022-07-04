#include <bits/stdc++.h>

using namespace std;

int findCeil(vector<int> v, int num){
    int left = 0, right = v.size() - 1;
    int res = -1;
    while(left <= right){
        int mid = left + (right - left) / 2;
        if(v[mid] >= num){
            res = v[mid];
            right = mid - 1;
        }
        else
            left = mid + 1;
    }
    return res;
} 

int main() {
    int n;
    cin >> n;
	vector<int> res(n);
	for(int i = 0; i < n; ++i) {
	    cin >> res[i];
	}
	sort(res.begin(), res.end());
	int target;
	cin >> target;
	cout << findCeil(res, target) << "\n";
}
