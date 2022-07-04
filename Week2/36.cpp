class Solution {
public:
    int trap(vector<int>& height) {
        /*int res = 0;
        stack<int> st;
        int curr = 0;
        while(curr < height.size()){
            while(!st.empty() && height[curr] > height[st.top()]) {
                int base = st.top();
                st.pop();
                if(st.empty())
                    break;
                int dist = curr - st.top() - 1;
                int ht = min(height[curr], height[st.top()]) - height[base];
                res += dist * ht;
            }
            st.push(curr++);
        }
        return res;*/
        int left = 0, right = height.size() - 1;
        int res = 0;
        int leftMax = 0, rightMax = 0;
        while(left < right){
            if(height[left] < height[right]){
                if(height[left] < leftMax){
                    res += leftMax - height[left];
                }
                else {
                    leftMax = height[left];
                }
                ++left;
            }
            else {
                if(height[right] < rightMax)
                    res += rightMax - height[right];
                else
                    rightMax = height[right];
                --right;
            }
        }
        return res;
    }
};
