#include<bits/stdc++.h>
using namespace std;

bool testOccurrence(vector<int>& nums, int target){
  int left = 0, right = nums.size() - 1;
  while(left <= right){
    int mid = left + (right - left) / 2;
    if((mid == 0 || nums[mid - 1] < nums[mid]) && nums[mid] == target)
    {
      if(((mid + nums.size()) / 2 <= nums.size() - 1) && nums[mid + nums.size() / 2] == nums[mid])
        return true;
      return false;
    }
    else if(nums[mid] < target){
      left = mid  + 1;
    }
    else
      right = mid - 1;
  }
  return false;
}


int main(){
  vector<int> nums = {1, 2, 3, 4, 5, 5, 5, 5, 5, 7};
  int target = 3;
  if(testOccurrence(nums, target))
    cout << "The number " << target << " occurs more than " << nums.size() << "/2 times in the array." << endl;
  else
    cout << "The number " << target << " does not occur more than " << nums.size() << "/2 times in the array." << endl;
}
