class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int total = (nums1.size() + nums2.size() + 1) / 2;
        int minSize = nums2.size() < nums1.size() ? nums2.size() : nums1.size();
        int left = 0, right = minSize;
        int parX, parY;
      //Swap the arrays so that nums1 is always the smaller array, to avoid confusion
        if(nums2.size() < nums1.size()){
            vector<int> temp;
            temp = nums2;
            nums2 = nums1;
            nums1 = temp;
        }
        while(left <= right){
          //Finding the elements between which to partition the arrays
            parX = left + (right - left) / 2;
            parY = total - parX;
          //Finding the values of elements to the left and right of the partition
          //If the partition has 0 elements to either side, assign INT_MAX and INT_MIN accordingly
            int leftX = (parX == 0 ? INT_MIN : nums1[parX - 1]);
            int rightX = (parX == nums1.size() ? INT_MAX : nums1[parX]);
            int leftY = (parY == 0 ? INT_MIN : nums2[parY - 1]);
            int rightY = (parY == nums2.size() ? INT_MAX : nums2[parY]);
            if(leftX <= rightY && rightX >= leftY){
                int max = leftX > leftY ? leftX : leftY;
                int min = rightX < rightY ? rightX : rightY;
                if((nums1.size() + nums2.size()) % 2 == 0)
                    return (double)(max + min) / 2;
                else
                    return max;
            }
          //If element to the right of partition X is smaller than the max element
          //to the left of partition Y, we need to move partition X further to the right and
          //thus partition Y further to the left
            if(rightX < leftY)
                left = parX + 1;
            else if (rightY < leftX)
                right = parX - 1;
        }
        return -1;
    }
};
